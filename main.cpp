#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include "yocto_api.h"
#include "yocto_display.h"
#include "yocto_anbutton.h"

using namespace std;

#define HOTSPOT_NAME "yHotSpot"
#define PASSWORD_EXPIRATION (3600) //password expire after 1 hour
#define PASSWORD_LENGTH     (10) 
#define WIFI_CONFIG_FILE "/etc/config/wireless"
#define WIFI_CONFIG_TMP_FILE "/tmp/wireless.tmp"
#define WIFI_CONFIG_OLD_FILE "/etc/config/wireless.old"
#define PRESS_BUTTON_SEQ  "press.seq"

static const char allowedchar[] =
"23456789."
"ABCDEFGHJKMNPQRSTUVWXYZ"
"abcdefghjkmnpqrstuvwxyz";

YDisplay    *Display = NULL;
YAnButton   *Button = NULL;
int         IsWifiUp = 0;
char        SecretKey[PASSWORD_LENGTH+1];
time_t      PasswordExpiration=0;

typedef enum {
    WELCOME_MSG, STARTING_MSG, HOTSPOT_MSG, COLDSPOT_MSG
} MSG_TYPE;

static void animateArrow(void)
{
    YDisplayLayer  *l1 = Display->get_displayLayer(1);
    int             hw = 4;

    l1->hide();
    l1->clear();
    l1->moveTo(64-hw,64-6*hw);
    l1->lineTo(64+hw,64-6*hw);
    l1->lineTo(64+hw,64-4*hw);
    l1->lineTo(64+2*hw,64-4*hw);
    l1->lineTo(64,64-hw);
    l1->lineTo(64-2*hw,64-4*hw);
    l1->lineTo(64-hw,64-4*hw);
    l1->lineTo(64-hw,64-6*hw);
    l1->setLayerPosition(0, -hw, 0);
    l1->unhide();
    l1->setLayerPosition(0, hw-1, 700);
}

static void showMessage(MSG_TYPE msg)
{
    switch(msg) {
        case WELCOME_MSG:
            cout << "INFO: Welcome message" << endl;
            break;
        case STARTING_MSG:
            cout << "INFO: Starting WiFi" << endl;
            break;
        case HOTSPOT_MSG:
            cout << "INFO: HotSpot started, key=" << SecretKey << endl;
            break;
        case COLDSPOT_MSG:
            cout << "INFO: Canoot start WiFi" << endl;
            break;
    }

    if (Display==NULL || !Display->isOnline()) {
        cerr << "No Yocto-Display connected (check USB cable)" << endl;
        return;
    }

    Display->resetAll();
    // retreive the display size
    int w = Display->get_displayWidth();
    int h = Display->get_displayHeight();

    // display text on first layer
    YDisplayLayer *l0 = Display->get_displayLayer(0);
    l0->selectFont("Medium.yfm");
    switch(msg) {
        case WELCOME_MSG:
            l0->drawText(w / 2, h * 3/8, YDisplayLayer::ALIGN_CENTER, "Press for WiFi");
            Display->playSequence(PRESS_BUTTON_SEQ);
            break;
        case STARTING_MSG:
            l0->drawText(w / 2, h / 2, YDisplayLayer::ALIGN_CENTER, "Starting WiFi...");
            break;
        case HOTSPOT_MSG:
            l0->drawText(w / 2, h * 3/8 - 2, YDisplayLayer::ALIGN_CENTER, HOTSPOT_NAME);
            l0->drawText(w / 2, h * 7/8 - 3, YDisplayLayer::ALIGN_CENTER, SecretKey);
            l0->selectFont("Small.yfm");
            l0->drawText(w / 2, h * 1/8 - 2, YDisplayLayer::ALIGN_CENTER, "Hotspot name:");
            l0->drawText(w / 2, h * 5/8 - 2, YDisplayLayer::ALIGN_CENTER, "Secret key:");
            break;
        case COLDSPOT_MSG:
            l0->drawText(w / 2, h / 2, YDisplayLayer::ALIGN_CENTER, "Cannot start WiFi");
            break;
    }
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
        system("wifi down ; wifi up &");
        IsWifiUp = 1;
    }

    return 0;
}

static void stopWiFi(void)
{
    if(IsWifiUp) {
        system("wifi down &");
        showMessage(WELCOME_MSG);
        IsWifiUp=0;
    }
}

static void generatePasswd(char * buffer)
{
    int i;
    int modulo = sizeof(allowedchar) - 1;
    for (i=0; i< PASSWORD_LENGTH; i++) {
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
        showMessage(STARTING_MSG);
        generatePasswd(SecretKey);
        if (startWiFi(SecretKey) < 0) {
            showMessage(COLDSPOT_MSG);
            return;
        }
        showMessage(HOTSPOT_MSG);
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
    srand(time(NULL));

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
        if (IsWifiUp) {
            if(time(NULL) > PasswordExpiration) {
                stopWiFi();
            } 
        } else {
            animateArrow();
        }
        YAPI::Sleep(1000, errmsg);   // traps others events
    } 
    return 0;
}
