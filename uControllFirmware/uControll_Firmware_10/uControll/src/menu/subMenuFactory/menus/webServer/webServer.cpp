#include "webServer.h"

WebServerMenu::WebServerMenu(HttpClient* aClient, subMenu* aNextMenu):client(aClient){
    this->nextMenu = aNextMenu;
};

subMenu *WebServerMenu::WebServer()
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