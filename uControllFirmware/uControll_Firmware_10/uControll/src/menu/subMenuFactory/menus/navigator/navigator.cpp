
#include "navigator.h"

NavigatorMenu::NavigatorMenu(subMenu *aNextMenu) : nextMenu(aNextMenu){};

subMenu *NavigatorMenu::Navigator()
{
    subMenu *aMenu = new subMenu();

    aMenu->setTitle("<> Navigate");
    aMenu->addItem("Start", nullptr);
    aMenu->addItem("Settings", nullptr);
    aMenu->addItem("Debug", nullptr);
    
    return aMenu;
};