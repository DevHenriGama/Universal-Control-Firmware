#include "Menu.h"
#include "../entities/subMenu/subMenu.h"


Menu::Menu(LiquidCrystal_I2C& display): lcd(display){
  MenuIndex = 0;
  factory = subMenuFactory();
};

void Menu::PrintInDisplay(const char* atitle, const char* aItem){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.printstr(atitle);
    lcd.setCursor(0,1);
    lcd.printstr(aItem);
};

void Menu::AddSubMenu(subMenu asubMenu){
    menus.push_back(asubMenu);
};


void Menu::Initialize(){

    this->AddSubMenu(factory.Initial());  

    this->Render();

};

void Menu::Render(){

    //prevents display updates
    if(old_subMenu.getTitle() == menus[MenuIndex].getTitle() 
        && old_subMenu.getItemIndex() == menus[MenuIndex].getItemIndex()){

        return;
    }

    if(menus.size() == 0){
       PrintInDisplay("Err","menu not initialized."); 
       return;
    }

    const char* myTitle = menus[MenuIndex].getTitle().c_str();
    const char* myItem = "0 Itens";

    if(menus[MenuIndex].getTotalItens() > 0){
        int index = menus[MenuIndex].getItemIndex();
        myItem = menus[MenuIndex].getItens()[index].c_str();
    }

    
    PrintInDisplay(myTitle,myItem);

    old_subMenu = menus[MenuIndex];
};

void Menu::NavigateMenu(bool aBack, bool aNext){

    menus[MenuIndex].NavigateSubMenuItens(aBack,aNext);

    this-> Render();

};


void Menu::OperateMenu(bool aEnter, bool aLeave){
    if(aLeave && MenuIndex > 0 ){  
        MenuIndex--;
        return;
    }

    if(aEnter && MenuIndex < menus.size()){
        //Se entrar no proximo menu vai para o gerenciador de menus
        MenuIndex++;
    };

    this->Render();
};

