#ifndef SelectConnection_h
#define SelectConnection_h

#include "../../../../entities/subMenu/subMenu.h"

class SelectConnectionMenu
{
    private:
      subMenu* bluetooth;
      subMenu* radioFrequence;
      subMenu* webServer;
    public:
        SelectConnectionMenu(subMenu* aBluetooth,subMenu* aRadioFrequence,subMenu* aWebServer);
        subMenu* SelectConnection();
};

#endif
