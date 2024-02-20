#include <iostream>
#include "./subMenuFactory.h"
#include <string>

#include "../../connections/httpClient/httpClient.h"

#include "menus/webServer/webServer.h"

HttpClient *client = new HttpClient();

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
    WebServerMenu menu(client,Navigator());

    return menu.WebServer();
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
