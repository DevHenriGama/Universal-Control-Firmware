#include <RF24.h>
#include <LiquidCrystal_I2C.h>

struct MyData{
  int potValue;
};

MyData data;

RF24 radio(7,8);
LiquidCrystal_I2C led(0x27, 16,2);

const byte address[6] = "1Node";
void setup() {
  led.init();
  led.backlight();

  pinMode(A0, INPUT);
  
 if(!radio.begin()){
  Display("Bem Vindo","Radio not Resp.");
  while(1);
 }else{
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Display("Bem Vindo","Radio Iniciado!");
 }
}

void loop() {
 data.potValue = analogRead(A0);
 radio.write(&data, sizeof(MyData));
 delay(100);

}

void Display(String L1,String L2){
  led.clear();
  led.setCursor(0,0);
  led.print(L1);
  led.setCursor(0,1);
  led.print(L2);
}
