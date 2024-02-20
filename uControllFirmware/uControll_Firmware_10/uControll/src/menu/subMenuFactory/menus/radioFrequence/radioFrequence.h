#ifndef RadioFrequence_h
#define RadioFrequence_h

#include "../../../../entities/subMenu/subMenu.h"
#include "../../../../connections/httpClient/httpClient.h"

class RadioFrequenceMenu
{
    private:
      HttpClient* client;  
      subMenu* nextMenu;
    public:
        RadioFrequenceMenu(HttpClient* aClient, subMenu* aNextMenu);
        subMenu* RadioFrequence();
};

#endif
