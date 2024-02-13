#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <vector>
#include "../entities/subMenu/subMenu.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "./subMenuFactory/subMenuFactory.h"

using namespace std;

class Menu {

    private:
        int MenuIndex;
        std::vector<subMenu*> menus;
        LiquidCrystal_I2C& lcd;
        subMenu old_subMenu;
        subMenuFactory factory;
        void Render();
        void PrintInDisplay(const char* atitle, const char* aItem);
    public:
        Menu(LiquidCrystal_I2C& display);
        void NavigateMenu(bool aBack, bool aNext);
        void OperateMenu(bool aEnter, bool aLeave);
        void Initialize();
        
};

#endif