#ifndef Wifi_h
#define Wifi_h

#include <WiFi.h>

class WifiConnection
{
private:
    char* SSID;
    char* PASSWORD;
public:
    WifiConnection();
    void Initialize();
    WiFiClient getWiFi();
};

#endif