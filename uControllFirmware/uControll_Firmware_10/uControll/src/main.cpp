#include <Arduino.h>
#include <./menu/Menu.h>
#include <LiquidCrystal_I2C.h>

//create display object
LiquidCrystal_I2C lcd(0x27,16, 2);
Menu mainMenu(lcd);

bool aNext;
bool aBack;
static const uint8_t BACK = 4;
static const uint8_t NEXT = 5;

void Events(){
  mainMenu.NavigateMenu(aBack, aNext);

//   if(aNext){
//     Serial.printf("Next");
//   }
// if(aBack){
//     Serial.printf("Back");
//   }
};

void setup() {

Serial.begin(9600);

pinMode(BACK,INPUT_PULLUP);
pinMode(NEXT , INPUT_PULLUP);

lcd.init();
lcd.backlight();



//Start Logic

mainMenu.Initialize();
};

void loop() {
    aNext = !digitalRead(NEXT);
    aBack = !digitalRead(BACK);
    Events();
    delay(100);
};
