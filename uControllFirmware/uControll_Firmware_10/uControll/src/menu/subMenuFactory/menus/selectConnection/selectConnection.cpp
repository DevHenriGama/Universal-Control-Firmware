#include "selectConnection.h"

SelectConnectionMenu::SelectConnectionMenu(subMenu *aBluetooth, subMenu *aRadioFrequence, subMenu *aWebServer)
{
    bluetooth = aBluetooth;
    radioFrequence = aRadioFrequence;
    webServer = aWebServer;
};

subMenu *SelectConnectionMenu::SelectConnection()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("-> connection");
    aMenu->addItem("Radio.F", radioFrequence);
    aMenu->addItem("Bluetooth", bluetooth);
    aMenu->addItem("WebServer", webServer);

    return aMenu;
};