#include "httpConnectionMenu.h"

HTTPConnectionMenu::HTTPConnectionMenu(HttpClient* aClient, subMenu* aNextMenu):client(aClient){
    this->nextMenu = aNextMenu;
};

subMenu *HTTPConnectionMenu::HTTPConnection()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> WebServer");

    string payload = client->GET("https://api.agify.io/?name=meelad").c_str();

    if (payload != "")
    {   
        //deserialize request

        aMenu->addItem(payload, nextMenu);
        
    }
    return aMenu;
};