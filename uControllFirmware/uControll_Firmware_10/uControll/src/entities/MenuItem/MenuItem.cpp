#include <string>
#include <iostream>

#include "MenuItem.h"

using namespace std;

MenuItem::MenuItem(){
    itemName = "";
};
void MenuItem::setItemName(string aName){
    itemName = aName;
};
string MenuItem::getItemName(){
    return itemName;
};
void MenuItem::setNextMenu(subMenu* aNext){
    nextMenu = aNext;
};
subMenu* MenuItem::getNextMenu(){
    return nextMenu;
};  