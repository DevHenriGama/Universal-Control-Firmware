#include <Arduino.h>
#include <./menu/Menu.h>
#include <LiquidCrystal_I2C.h>

//create display object
LiquidCrystal_I2C lcd(0x27,16, 2);
Menu mainMenu(lcd);

bool aNext;
bool aBack;
bool aEnter;
bool aLeave;
static const uint8_t BACK = 4;
static const uint8_t NEXT = 5;
static const uint8_t ENTER = 27;
static const uint8_t LEAVE = 14;

void Events(){
  mainMenu.NavigateMenu(aBack, aNext);
  mainMenu.OperateMenu(aEnter,aLeave);

//   if(aLeave){
//     Serial.printf("Leave");
//   }
// if(aEnter){
//     Serial.printf("Enter");
//   }
};

void setup() {

Serial.begin(9600);

pinMode(BACK,INPUT_PULLUP);
pinMode(NEXT , INPUT_PULLUP);
pinMode(ENTER , INPUT_PULLUP);
pinMode(LEAVE , INPUT_PULLUP);

lcd.init();
lcd.backlight();
//Start Logic

mainMenu.Initialize();
};

void loop() {
    aNext = !digitalRead(NEXT);
    aBack = !digitalRead(BACK);
    aEnter = !digitalRead(ENTER);
    aLeave = !digitalRead(LEAVE);

    Events();
    delay(100);
};
