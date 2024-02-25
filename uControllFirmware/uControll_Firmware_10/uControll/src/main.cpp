#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>

#include "./menu/Menu.h"
#include "connections/wifi/wifiConnection.h"
#include "connections/webServer/WebServer.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);

Menu mainMenu(lcd);
WifiConnection wifi;
WebServer webserver;

bool aNext;
bool aBack;
bool aEnter;
bool aLeave;
static const uint8_t BACK = 4;
static const uint8_t NEXT = 5;
static const uint8_t ENTER = 27;
static const uint8_t LEAVE = 14;

void Events()
{
  mainMenu.NavigateMenu(aBack, aNext);
  mainMenu.OperateMenu(aEnter, aLeave);
};

void setup()
{
  //Start display before all
  lcd.init();
  lcd.backlight();

  //Start objects for operations 
  Serial.begin(9600);
  wifi.Initialize();
  webserver.Start();

  pinMode(BACK, INPUT_PULLUP);
  pinMode(NEXT, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
  pinMode(LEAVE, INPUT_PULLUP);

  mainMenu.Initialize();
};

void loop()
{
  aNext = !digitalRead(NEXT);
  aBack = !digitalRead(BACK);
  aEnter = !digitalRead(ENTER);
  aLeave = !digitalRead(LEAVE);

  Events();
  delay(100);
};
