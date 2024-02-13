#include<iostream>
#include "./subMenuFactory.h"

using namespace std;

subMenuFactory::subMenuFactory(){
    
};

subMenu* subMenuFactory::Initial(){

};
subMenu* subMenuFactory::Bluetooth(){};
subMenu* subMenuFactory::RadioFrequence(){};
subMenu* subMenuFactory::WebServer(){};
subMenu* subMenuFactory::Navigator(){};
subMenu* subMenuFactory::Settings(){};
subMenu* subMenuFactory::ProfileControl(){};
subMenu* subMenuFactory::debug(){};

subMenu* subMenuFactory::SelectConnection(){
    subMenu* aMenu = new subMenu();

    aMenu->setTitle("-> connection");
    aMenu->addItem("Radio.F", nullptr);
    aMenu->addItem("Bluetooth", nullptr);
    aMenu->addItem("WebServer", nullptr);
    
    return aMenu;
};

