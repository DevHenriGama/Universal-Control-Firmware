#ifndef subMenu_h
#define subMenu_h

#include <vector>
#include <iostream>
#include <string>

#include "../MenuItem/MenuItem.h"
#include "../../entities/device/Device.h"

using namespace std;

class subMenu
{

private:
    string title;
    int ItemIndex;
    std::vector<MenuItem> items;

public:
    subMenu();
    void setTitle(string aTitle);
    string getTitle();
    void addItem(string aItemName, subMenu *aNextMenu);
    void addItem(string aItemName, subMenu *aNextMenu, Device aDevice);
    std::vector<MenuItem> getItens();
    void NavigateSubMenuItens(bool aBack, bool aNext);
    int getItemIndex();
    int getTotalItens();
    MenuItem getItem();
};

#endif