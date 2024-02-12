#ifndef subMenu_h
#define subMenu_h

#include <string>
#include <vector>
#include <iostream>

#include "../../entities/menuItem/menuItem.h"

using namespace std;

class subMenu {

    private:
        int ItemIndex;
        string title;
        std::vector<MenuItem> itens;
    public:
     subMenu();
     void setTitle(string aTitle);
     string getTitle();
     void addItem(string aItemName, subMenu aNextMenu);
     std::vector<MenuItem> getItens();
     void NavigateSubMenuItens(bool aBack, bool aNext);
     int getItemIndex();
     int getTotalItens();
     MenuItem getItem();
     
};

#endif