#include "radioFrequence.h"

RadioFrequenceMenu::RadioFrequenceMenu(HttpClient *aClient, subMenu *aNextMenu) : client(aClient), nextMenu(aNextMenu){};

subMenu *RadioFrequenceMenu::RadioFrequence()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> Radio. F");

    if (true)
    {   //request from radio frequence API
        aMenu->addItem("Margot", nullptr);
        aMenu->addItem("Nightmare", nullptr);
        aMenu->addItem("pDrone", nullptr);
        aMenu->addItem("aVantTang", nullptr);
    }

    return aMenu;
};