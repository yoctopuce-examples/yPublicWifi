#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "yocto_api.h"
#include "yocto_display.h"
#include "yocto_anbutton.h"

using namespace std;

#define WELCOME_MSG "Press for WiFi"
#define PASSWORD_EXPIRATION (30)
#define WIFI_CONFIG_FILE "/etc/config/wireless"
#define WIFI_CONFIG_TMP_FILE "/tmp/wireless.tmp"
#define WIFI_CONFIG_OLD_FILE "/etc/config/wireless.old"

YDisplay    *Display = NULL;
YAnButton   *Button = NULL;
int         IsWifiUp=0;
time_t      PasswordExpriration=0;
string      currentPasswd="";


static void log (const string& line)
{
    cout << line;
}




static void showMessage(const char *msg)
{

    cout << "display :"<<msg << endl;

    if (!Display->isOnline()) {
        cerr << "Module is offline (check USB cable)" << endl;
        return;
    }

    Display->resetAll();
    // retreive the display size
    int w = Display->get_displayWidth();
    int h = Display->get_displayHeight();

    // reteive the first layer
    YDisplayLayer *l0 = Display->get_displayLayer(0);
    l0->clear();

    // display a text in the middle of the screen
    l0->selectFont("Medium.yfm");
    l0->drawText(w / 2, h / 2, YDisplayLayer::ALIGN_CENTER, msg);
}



static int startWifi(const char *password)
{
    FILE *in, *out;
    char buffer[256];
    int res=0;

    in = fopen (WIFI_CONFIG_FILE,"r");
    if (in==NULL) {
        perror("unable to open wireless file");
        return -1;
    }
    out = fopen (WIFI_CONFIG_TMP_FILE,"w");
    if (out==NULL) {
        perror("unable to open tmp wireless file");
        return -1;
    }
    
    while (fgets(buffer, 256, in) != NULL) {
        char *option = strstr(buffer, "option key");
        if (option){
            //todo: check for buffer overflow
            sprintf(option,"option key '%s'\n",password);            
        }
        if(fputs(buffer,out) == EOF){
            perror("unable to write tmp wireless file");
            res = -1;
            break;
        }  
    }
    fclose(in);
    fclose(out);

    if (res >= 0) {
        system("mv " WIFI_CONFIG_FILE " "WIFI_CONFIG_OLD_FILE);
        system("mv " WIFI_CONFIG_TMP_FILE " "WIFI_CONFIG_FILE);
        //reload config
        system("wifi down");
        system("wifi up");
        IsWifiUp = 1;
    }

    return 0;
}



static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";


static void generatePasswd(char * buffer,int len)
{
    int i;
    int modulo = sizeof(alphanum) - 1;
    for (i=0; i< len-1 ; i++) {
        int idx = rand() % modulo;
        *buffer++ = alphanum[idx];
    }
    *buffer=0;
}


static void anButtonValueChangeCallBack(YAnButton *bt, const string& value)
{
    if (!bt->get_isPressed()) {
        return;
    }

    time_t now = time(NULL);
    if(now > PasswordExpriration) {
        showMessage("starting WiFi...");
        cout << "generate new Password"<< endl;
        char newpass[9];
        generatePasswd(newpass,9);
        cout << "new password is "<<newpass << endl;
        if (startWifi(newpass) < 0) {
            showMessage("unable to start WiFi");
            return;
        }
        showMessage(newpass);
        cout << "wifi is ok"<<newpass << endl;
    }

    PasswordExpriration = now + PASSWORD_EXPIRATION;
}


static void deviceArrival(YModule *m)
{
    string serial = m->get_serialNumber();
    string product = m->get_productName();
    if( product == "Yocto-MaxiDisplay" ||
        product == "Yocto-Display") {
        Display = YDisplay::FindDisplay(serial+".display");
        Button = YAnButton::FindAnButton(serial+".anButton1");
        Button->registerValueCallback(anButtonValueChangeCallBack);
        showMessage(WELCOME_MSG);
    }
}


static void deviceRemoval(YModule *m)
{
    string serial = m->get_serialNumber();
    cout << "Device removal : " << serial << endl;

    if( serial == Display->module()->get_serialNumber()) {
        if (IsWifiUp) {
            system("wifi down");
        }
        Display = NULL;
        Button = NULL;        
    }
}




int main(int argc, const char * argv[])
{
    string      errmsg;

    // stop Wifi
    system("wifi down");


    YAPI::RegisterLogFunction(log);
    // Setup the API to use local USB devices
    if(YAPI::RegisterHub("usb", errmsg) != YAPI_SUCCESS) {
        cerr << "RegisterHub error: " << errmsg << endl;
        return 1;
    }


    YAPI::RegisterDeviceArrivalCallback(deviceArrival);
    YAPI::RegisterDeviceRemovalCallback(deviceRemoval);
    YAPI::DisableExceptions();
    
    if (YAPI::RegisterHub("usb", errmsg) != YAPI::SUCCESS) {
        cerr << "RegisterHub error : " << errmsg<<endl;
        return 1;
    }

    cout << "Hit Ctrl-C to Stop " << endl;

    while (true) {
        YAPI::UpdateDeviceList(errmsg); // traps plug/unplug events
        YAPI::Sleep(1000, errmsg);   // traps others events
        if (IsWifiUp){
            time_t t;
            t = time(NULL);
            if (t > PasswordExpriration ) {
                system("wifi down");
                IsWifiUp=0;
                showMessage(WELCOME_MSG);
            }
        }
    } 
    return 0;
}
