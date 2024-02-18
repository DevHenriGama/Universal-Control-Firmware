#ifndef MenuItem_h
#define MenuItem_h

#include <string>
#include <iostream>

#include "../device/Device.h"

class subMenu;

using namespace std;

class MenuItem {

    private:
        Device device;
        string itemName ;
        subMenu* nextMenu;
    public:
        MenuItem();
        void setItemName(string aName);
        string getItemName();
        void setNextMenu(subMenu* aNext);
        subMenu* getNextMenu();  
        void setDevice(Device aDevice);
        Device getDevice();
};

#endif