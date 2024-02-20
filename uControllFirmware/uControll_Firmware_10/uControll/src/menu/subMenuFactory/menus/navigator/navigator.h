#ifndef Navigator_h
#define Navigator_h

#include "../../../../entities/subMenu/subMenu.h"

class NavigatorMenu
{
    private:
      subMenu* nextMenu;
    public:
        NavigatorMenu(subMenu* aNextMenu);
        subMenu* Navigator();
};

#endif
