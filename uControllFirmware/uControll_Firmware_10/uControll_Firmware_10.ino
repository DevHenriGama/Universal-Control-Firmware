//Inclusão das Libarys
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

#define led_conn 6
#define mov_button 4
#define ok_button 5
#define joyLeft_btn 9
#define joyRight_btn 10
#define joyLeft_A A2
#define joyLeft_B A3
#define joyRigth_A A0
#define joyRigth_B A1
#define NumPage 3
#define Buzz 3


//Estrutura de dados

struct MyData {
 int DT_joyL_A = 90;
 int DT_joyL_B = 90;
 int DT_joyR_A = 90;
 int DT_joyR_B = 90;
 bool DT_joyL_btn = false;
 bool DT_joyR_btn = false;
};

MyData data;

//Variaveis do Controle
bool ledConn_state = false;
int joyL_pos_A;
int joyL_pos_B;
int joyR_pos_A;
int joyR_pos_B;
bool joyL_button_state;
bool joyR_button_state;
bool mov_button_state;
bool ok_button_state;

//Display LIst Logic
String Menu[NumPage] = {"EixL","EixR" ,"CoN"}; 
String PageDesc[NumPage] = {"Settings L-Side","Settings R-Side","Connection Info"};
int PagePosi = 0;
bool MenuState = true;

const byte address[6] = "1Node";

LiquidCrystal_I2C display(0x27,16,2);
RF24 radio(7,8); //CE - CSN

void setup() { 
  //Inicialização
  Serial.begin(115200);
  display.init();
  display.backlight();
  
  //Definição das Entradas
  Display("uControll Sys", "Loading Modules");
  pinMode(led_conn,OUTPUT);
  pinMode(mov_button, INPUT_PULLUP);
  pinMode(ok_button,INPUT_PULLUP);
  pinMode(joyLeft_btn,INPUT_PULLUP);
  pinMode(joyRight_btn,INPUT_PULLUP);
  pinMode(joyLeft_A , INPUT);
  pinMode(joyLeft_B , INPUT);
  pinMode(joyRigth_A, INPUT);
  pinMode(joyRigth_B, INPUT);
  pinMode(Buzz,OUTPUT);
  delay(2000);
  
  Display("uControll Sys", "Modules Loaded!");
  delay(2500);

  Display("uControll Sys", "Loading RadioF.");
  if(!radio.begin()){
   Display("uControll - RF OFF","By - Henrique"); 
   while(1);
  }else{
  delay(1000);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Display("uControll Sys", "RadioF. Loaded.");
  }

delay(3000);
//LedIndicator();
}

void loop() {  

if(!ok_button_state){
  MenuState = !MenuState;
  bep();
}
  
if(MenuState){
  
  if(!mov_button_state){
    if(PagePosi < NumPage){
        PagePosi += 1;  
      }else{
        PagePosi = 0;
       } 
       bep(); 
    }

    Display("Menu -> " + Menu[PagePosi],PageDesc[PagePosi]);
}else{
  switch(PagePosi){
      case 0 : ShowEixL();
    break;
       case 1: ShowEixR();
      break;
    
  }
}


//Display(String(MenuState),Menu[PagePosi]);



//OK-----------  
ReadValues();
Transmiter();  
   delay(100);    
}

void ReadControll(){

}
void Display(String Line1, String Line2){
  display.clear();
  display.setCursor(0,0);
  display.print(Line1);
  display.setCursor(0,1);
  display.print(Line2);
}
void Transmiter(){  
  data.DT_joyL_A = joyL_pos_A;
  data.DT_joyL_B = joyL_pos_B;
  data.DT_joyL_btn  = joyL_button_state;
  data.DT_joyR_A = joyR_pos_A;
  data.DT_joyR_B = joyR_pos_B;
  data.DT_joyR_btn = joyR_button_state;
  radio.write(&data, sizeof(MyData));   
}

void DebugInfo(){
  Serial.println("JoyL -A :" + String(joyL_pos_A)); 
  Serial.println("JoyL -B :" + String(joyL_pos_B));
  Serial.println("JoyL Button :" + String(joyL_button_state));
  Serial.println("JoyR -A :" + String(joyR_pos_A ));
  Serial.println("JoyR -B :" + String(joyR_pos_B ));  
  Serial.println("JoyR Button :" + String(joyR_button_state));
  Serial.println("Next Button:" + String(ok_button_state ));    
  Serial.println("Prev Button:" + String(mov_button_state ));
  Serial.println("----------------end info------------------");

}
void LedIndicator(){
  digitalWrite(led_conn, HIGH);
}
void ReadValues(){
    joyL_pos_A = analogRead(joyLeft_A);
  joyL_pos_B  = analogRead(joyLeft_B);
  joyR_pos_A = analogRead(joyRigth_A);
  joyR_pos_B = analogRead(joyRigth_B);
  joyR_button_state = digitalRead(joyRight_btn);
  joyL_button_state = digitalRead(joyLeft_btn);
  ok_button_state = digitalRead(ok_button);
  mov_button_state = digitalRead(mov_button);
}
void ShowEixL(){
  Display(Menu[PagePosi],
  "X: "+String(joyL_pos_A)+
   " Y:"+ String(joyL_pos_B));
}
void ShowEixR(){
    Display(Menu[PagePosi],
  "X: "+String(joyR_pos_A)+
   " Y:"+ String(joyR_pos_B));
}

void bep(){
  tone(Buzz,1000,100);
  //delay(50);
  //noTone(Buzz);
}
