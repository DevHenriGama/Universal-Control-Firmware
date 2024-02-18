#include "subMenu.h"
#include "../MenuItem/MenuItem.h"
#include <string>

using namespace std;

subMenu::subMenu()
{
    this->title = "";
    this->ItemIndex = 0;
};

void subMenu::setTitle(string aTitle)
{
    this->title = aTitle;
};
string subMenu::getTitle()
{
    return this->title;
};

void subMenu::addItem(string aItemName, subMenu *aNextMenu)
{
    MenuItem Item;

    Item.setItemName(aItemName);
    Item.setNextMenu(aNextMenu);

    items.push_back(Item);
};

void subMenu::addItem(string aItemName, subMenu *aNextMenu, Device aDevice)
{
    MenuItem Item;

    Item.setItemName(aItemName);
    Item.setNextMenu(aNextMenu);
    Item.setDevice(aDevice);

    items.push_back(Item);
};

std::vector<MenuItem> subMenu::getItens()
{
    return this->items;
};

int subMenu::getTotalItens()
{
    return this->items.size();
};

void subMenu::NavigateSubMenuItens(bool aBack, bool aNext)
{
    if (aBack && ItemIndex > 0)
    {

        if (ItemIndex == 0)
        {
            ItemIndex = items.size() - 1;
            return;
        }

        ItemIndex--;
    }

    if (aNext && ItemIndex < items.size())
    {

        if (ItemIndex == items.size() - 1)
        {
            ItemIndex = 0;
            return;
        }

        ItemIndex++;
    }
};

int subMenu::getItemIndex()
{
    return this->ItemIndex;
};

MenuItem subMenu::getItem()
{
    return this->items[ItemIndex];
};
