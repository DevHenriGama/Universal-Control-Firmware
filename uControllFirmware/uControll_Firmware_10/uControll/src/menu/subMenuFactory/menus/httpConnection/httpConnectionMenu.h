#ifndef HTTPConnection_h
#define HTTPConnection_h

#include "../../../../entities/subMenu/subMenu.h"
#include "../../../../connections/httpClient/httpClient.h"

class HTTPConnectionMenu
{
    private:
      HttpClient* client;  
      subMenu* nextMenu;
    public:
        HTTPConnectionMenu(HttpClient* aClient, subMenu* aNextMenu);
        subMenu* HTTPConnection();
};

#endif
