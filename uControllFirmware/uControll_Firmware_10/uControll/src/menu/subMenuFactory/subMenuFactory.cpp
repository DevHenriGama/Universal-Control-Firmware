#include <iostream>
#include "./subMenuFactory.h"
#include <string>

#include "../../connections/httpClient/httpClient.h"

HttpClient client;

using namespace std;

subMenuFactory::subMenuFactory(){

};

subMenu *subMenuFactory::Initial(){

};
subMenu *subMenuFactory::Bluetooth(){};
subMenu *subMenuFactory::RadioFrequence()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> Radio. F");
    aMenu->addItem("Margot", nullptr);
    aMenu->addItem("Nightmare", nullptr);
    aMenu->addItem("pDrone", nullptr);
    aMenu->addItem("aVantTang", nullptr);

    return aMenu;
};
subMenu *subMenuFactory::WebServer()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> WebServer");

    string payload = client.GET("https://api.agify.io/?name=meelad").c_str();

    if (payload != "")
    {
        aMenu->addItem(payload, Navigator());
        // aMenu->addItem("Bunny", Navigator());
    }
    return aMenu;
};
subMenu *subMenuFactory::Navigator()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> Navigate");
    aMenu->addItem("Start", nullptr);
    aMenu->addItem("Settings", nullptr);
    aMenu->addItem("Debug", nullptr);
    return aMenu;
};
subMenu *subMenuFactory::Settings(){

};
subMenu *subMenuFactory::ProfileControl(){};
subMenu *subMenuFactory::debug(){};

subMenu *subMenuFactory::SelectConnection()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("-> connection");
    aMenu->addItem("Radio.F", RadioFrequence());
    aMenu->addItem("Bluetooth", nullptr);
    aMenu->addItem("WebServer", WebServer());

    return aMenu;
};
