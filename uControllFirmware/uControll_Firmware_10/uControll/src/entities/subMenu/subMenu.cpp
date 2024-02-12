#include "./subMenu.h"
#include "../../entities/menuItem/menuItem.h"
using namespace std;

subMenu::subMenu(){
    title = "";
    ItemIndex = 0;
};

void subMenu::setTitle(string aTitle){
    title = aTitle;
};
string subMenu::getTitle(){
    return title;    
};

void subMenu::addItem(string aItemName, subMenu aNextMenu){
    MenuItem Item;

    Item.setItemName(aItemName);
    Item.setNextMenu(aNextMenu);

    itens.push_back(Item);
};

std::vector<MenuItem> subMenu::getItens(){
    return itens;
};

int subMenu::getTotalItens(){
    return itens.size();
};

void subMenu::NavigateSubMenuItens(bool aBack, bool aNext){
    if(aBack && ItemIndex > 0){
    

        if(ItemIndex == 0 ){
            ItemIndex = itens.size() - 1 ;
            return;
        }

        ItemIndex --;
    }

    if(aNext && ItemIndex < itens.size()){

        if(ItemIndex == itens.size() - 1 ){
            ItemIndex = 0;
            return;
        }

        ItemIndex++;

    }
};


int subMenu::getItemIndex(){
    return this->ItemIndex;
};

MenuItem subMenu::getItem(){
    return itens[ItemIndex];
};

