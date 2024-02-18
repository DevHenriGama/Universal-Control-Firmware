#include "Menu.h"
#include "../entities/subMenu/subMenu.h"

Menu::Menu(LiquidCrystal_I2C &display) : lcd(display)
{
    MenuIndex = 0;
};

void Menu::PrintInDisplay(const char *atitle, const char *aItem)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.printstr(atitle);
    lcd.setCursor(0, 1);
    lcd.printstr(aItem);
};

void Menu::Initialize()
{

    menus.push_back(factory.SelectConnection());

    this->Render();
};

void Menu::Render()
{

    // prevents display refresh
    if (old_subMenu.getTitle() == menus[MenuIndex]->getTitle() && old_subMenu.getItemIndex() == menus[MenuIndex]->getItemIndex())
    {
        return;
    }

    if (menus.empty())
    {
        PrintInDisplay("Err", "Initialize Menu");
        return;
    }

    string menuTitle = menus[MenuIndex]->getTitle();
    const char *myItem = "0 Itens";

    if (menus[MenuIndex]->getTotalItens() > 0)
    {
        int index = menus[MenuIndex]->getItemIndex();
        myItem = menus[MenuIndex]->getItens()[index].getItemName().c_str();
    }

    PrintInDisplay(menuTitle.c_str(), myItem);

    old_subMenu = *menus[MenuIndex];
};

void Menu::NavigateMenu(bool aBack, bool aNext)
{

    menus[MenuIndex]->NavigateSubMenuItens(aBack, aNext);

    this->Render();
};

void Menu::OperateMenu(bool aEnter, bool aLeave)
{

    if (aLeave && MenuIndex > 0)
    {
        menus.pop_back();
        MenuIndex--;
    }

    if (aEnter)
    {
        MenuItem currentItem = menus[MenuIndex]->getItem();

        subMenu *nextSubMenu = currentItem.getNextMenu();

        if (nextSubMenu != nullptr && !nextSubMenu->getTitle().empty())
        {
            menus.push_back(nextSubMenu);
            MenuIndex++;
        }
    };

    this->Render();
};
