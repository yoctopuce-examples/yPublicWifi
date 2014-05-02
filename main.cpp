#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include "yocto_api.h"
#include "yocto_display.h"
#include "yocto_anbutton.h"

using namespace std;

#define WELCOME_MSG "Press for WiFi"
#define PASSWORD_EXPIRATION (3600) //password expire after 1 hour
#define PASSWORD_LENGHT (10) 
#define WIFI_CONFIG_FILE "/etc/config/wireless"
#define WIFI_CONFIG_TMP_FILE "/tmp/wireless.tmp"
#define WIFI_CONFIG_OLD_FILE "/etc/config/wireless.old"

static const char allowedchar[] =
"23456789."
"ABCDEFGHIJKMNPQRSTUVWXYZ"
"abcdefghjkmnpqrstuvwxyz";

YDisplay    *Display = NULL;
YAnButton   *Button = NULL;
int         IsWifiUp=0;
time_t      PasswordExpiration=0;

static void showMessage(const char *msg)
{

    cout << msg << endl;

    if (Display==NULL || !Display->isOnline()) {
        cerr << "No Yocto-Display connected (check USB cable)" << endl;
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

static int startWiFi(const char *password)
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

static void stopWiFi(void)
{
    if(IsWifiUp) {
        system("wifi down");
        showMessage(WELCOME_MSG);
        IsWifiUp=0;
    }
}

static void generatePasswd(char * buffer,int len)
{
    int i;
    int modulo = sizeof(allowedchar) - 1;
    for (i=0; i< len-1 ; i++) {
        int idx = rand() % modulo;
        *buffer++ = allowedchar[idx];
    }
    *buffer=0;
}

static void anButtonValueChangeCallBack(YAnButton *bt, const string& value)
{
    if (!bt->get_isPressed()) {
        return;
    }

    if (!IsWifiUp) {
        showMessage("starting WiFi...");
        char newpass[PASSWORD_LENGHT+1];
        generatePasswd(newpass,PASSWORD_LENGHT + 1);
        if (startWiFi(newpass) < 0) {
            showMessage("unable to start WiFi");
            return;
        }
        showMessage(newpass);
    }

    PasswordExpiration = time(NULL) + PASSWORD_EXPIRATION;
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
        stopWiFi();
        Display = NULL;
        Button = NULL;        
    }
}


static void usage()
{
    cout << "usage: yPublicWiFi <-d> " << endl;
    cout << "       -d : start yPublicWiFi in background" << endl;
    exit(1);
}


int main(int argc, const char * argv[])
{
    string      errmsg;

    if (argc > 1){
        if (argv[1][0]=='-' && argv[1][1]=='d') {
            // start yPublicWiFi in Background
            if (daemon(0, 0) < 0) {
                exit(1);
            }
        } else {
            usage();
        }
    }

    stopWiFi();
    YAPI::RegisterDeviceArrivalCallback(deviceArrival);
    YAPI::RegisterDeviceRemovalCallback(deviceRemoval);
    YAPI::DisableExceptions();
    
    if (YAPI::RegisterHub("usb", errmsg) != YAPI::SUCCESS) {
        cerr << "RegisterHub error : " << errmsg<<endl;
        return 1;
    }

    while (true) {
        YAPI::UpdateDeviceList(errmsg); // traps plug/unplug events
        YAPI::Sleep(1000, errmsg);   // traps others events
        if (time(NULL) > PasswordExpiration ) {
            stopWiFi();
        }
    } 
    return 0;
}
