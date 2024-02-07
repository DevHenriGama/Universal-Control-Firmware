#include "./subMenu.h"

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

void subMenu::addItem(string aItem){
    itens.push_back(aItem);
};

std::vector<std::string> subMenu::getItens(){
    return itens;
};

int subMenu::getTotalItens(){
    return itens.size();
};

void subMenu::NavigateSubMenuItens(bool aBack, bool aNext){
    if(aBack && ItemIndex > 0){
        //Infinte menu navigation
        if(ItemIndex == 0 ){
            ItemIndex = itens.size() - 1 ;
            return;
        }
        ItemIndex --;
    }

    if(aNext && ItemIndex < itens.size()){
        //Infinte menu navigation
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