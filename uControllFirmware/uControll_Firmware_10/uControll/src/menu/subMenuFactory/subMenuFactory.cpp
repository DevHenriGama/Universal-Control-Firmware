#include<iostream>
#include "./subMenuFactory.h"

using namespace std;

subMenuFactory::subMenuFactory(){
    
};

subMenu subMenuFactory::Initial(){
    subMenu aMenu;
    aMenu.setTitle("-> connection");
    aMenu.addItem("Radio.F");
    aMenu.addItem("Bluetooth");
    aMenu.addItem("WebServer");
    
    return aMenu;
};
subMenu subMenuFactory::Bluetooth(){};
subMenu subMenuFactory::RadioFrequence(){};
subMenu subMenuFactory::WebServer(){};
subMenu subMenuFactory::Navigator(){};
subMenu subMenuFactory::Settings(){};
subMenu subMenuFactory::ProfileControl(){};
subMenu subMenuFactory::debug(){};