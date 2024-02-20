#include "wifiConnection.h"
#include "Arduino.h"

WifiConnection::WifiConnection()
{
    PASSWORD = "97076226";
    SSID = "Henrique ";
};

void WifiConnection::Initialize()
{
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("Connecting...");
    };

    Serial.print("Connected");
};

WiFiClient WifiConnection::getWiFi(){
    
};