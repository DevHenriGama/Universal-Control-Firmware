#include<iostream>
#include "./subMenuFactory.h"

using namespace std;

subMenuFactory::subMenuFactory(){
    
};

subMenu subMenuFactory::Initial(){

};
subMenu subMenuFactory::Bluetooth(){};
subMenu subMenuFactory::RadioFrequence(){};
subMenu subMenuFactory::WebServer(){};
subMenu subMenuFactory::Navigator(){};
subMenu subMenuFactory::Settings(){};
subMenu subMenuFactory::ProfileControl(){};
subMenu subMenuFactory::debug(){};
subMenu subMenuFactory::SelectConnection(){
    subMenu aMenu;
    aMenu.setTitle("-> connection");
    aMenu.addItem("Radio.F",RadioFrequence());
    aMenu.addItem("Bluetooth",Bluetooth());
    aMenu.addItem("WebServer",WebServer());
    
    return aMenu;
};

