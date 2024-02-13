#ifndef MenuItem_h
#define MenuItem_h

#include <string>
#include <iostream>

class subMenu;

using namespace std;

class MenuItem {

    private:
        string itemName ;
        subMenu* nextMenu;
    public:
        MenuItem();
        void setItemName(string aName);
        string getItemName();
        void setNextMenu(subMenu* aNext);
        subMenu* getNextMenu();        
};

#endif