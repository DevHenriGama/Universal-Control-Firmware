#include <string>
#include <iostream>

#include "./menuItem.h"
#include "../subMenu/subMenu.h"

using namespace std;

MenuItem::MenuItem(){
    itemName = "";
    nextMenu = 0;
};
void MenuItem::setItemName(string aName){
    itemName = aName;
};
string MenuItem::getItemName(){
    return itemName;
};
void MenuItem::setNextMenu(subMenu aNext){
    nextMenu = aNext;
};
subMenu MenuItem::getNextMenu(){
    return nextMenu;
};  