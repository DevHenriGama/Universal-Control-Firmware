#include<iostream>
#include "./subMenuFactory.h"

using namespace std;

subMenuFactory::subMenuFactory(){
    
};

subMenu* subMenuFactory::Initial(){

};
subMenu* subMenuFactory::Bluetooth(){};
subMenu* subMenuFactory::RadioFrequence(){
    subMenu* aMenu = new subMenu();

    aMenu->setTitle("-> Radio. F");
    aMenu->addItem("Margot",nullptr);
    aMenu->addItem("Nightmare",nullptr);
    aMenu->addItem("pDrone",nullptr);
    aMenu->addItem("aVantTang",nullptr);

    return aMenu;
};
subMenu* subMenuFactory::WebServer(){};
subMenu* subMenuFactory::Navigator(){};
subMenu* subMenuFactory::Settings(){};
subMenu* subMenuFactory::ProfileControl(){};
subMenu* subMenuFactory::debug(){};

subMenu* subMenuFactory::SelectConnection(){
    subMenu* aMenu = new subMenu();

    aMenu->setTitle("-> connection");
    aMenu->addItem("Radio.F", RadioFrequence());
    aMenu->addItem("Bluetooth", nullptr);
    aMenu->addItem("WebServer", nullptr);
    
    return aMenu;
};

