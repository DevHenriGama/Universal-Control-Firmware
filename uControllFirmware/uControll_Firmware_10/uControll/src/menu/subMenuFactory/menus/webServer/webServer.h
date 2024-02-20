#ifndef WebServer_h
#define WebServer_h

#include "../../../../entities/subMenu/subMenu.h"
#include "../../../../connections/httpClient/httpClient.h"

class WebServerMenu
{
    private:
      HttpClient* client;  
      subMenu* nextMenu;
    public:
        WebServerMenu(HttpClient* aClient, subMenu* aNextMenu);
        subMenu* WebServer();
};

#endif
