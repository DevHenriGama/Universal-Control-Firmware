#include <iostream>
#include "./subMenuFactory.h"
#include <string>

#include "../../connections/httpClient/httpClient.h"

#include "menus/httpConnection/httpConnectionMenu.h"
#include "menus/selectConnection/selectConnection.h"
#include "menus/radioFrequence/radioFrequence.h"
#include "menus/navigator/navigator.h"

HttpClient *client = new HttpClient();

using namespace std;

subMenuFactory::subMenuFactory(){

};

subMenu *subMenuFactory::Initial(){

};
subMenu *subMenuFactory::Bluetooth(){ 
    return nullptr;
};
subMenu *subMenuFactory::RadioFrequence()
{
 RadioFrequenceMenu menu(client, Navigator());

 return menu.RadioFrequence();
};
subMenu *subMenuFactory::HTTPConnection()
{
    HTTPConnectionMenu menu(client,Navigator());

    return menu.HTTPConnection();
};

subMenu *subMenuFactory::Navigator()
{
 NavigatorMenu menu(nullptr);

 return menu.Navigator();
};
subMenu *subMenuFactory::Settings(){

};
subMenu *subMenuFactory::ProfileControl(){};
subMenu *subMenuFactory::debug(){};

subMenu *subMenuFactory::SelectConnection()
{
 SelectConnectionMenu menu(Bluetooth(), RadioFrequence(),HTTPConnection());

 return menu.SelectConnection();

};
