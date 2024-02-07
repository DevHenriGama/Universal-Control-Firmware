#ifndef subMenu_h
#define subMenu_h

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class subMenu {

    private:
        int ItemIndex;
        string title;
        std::vector<std::string> itens;
    public:
     subMenu();
     void setTitle(string aTitle);
     string getTitle();
     void addItem(string aItem);
     std::vector<std::string> getItens();
     void NavigateSubMenuItens(bool aBack, bool aNext);
     int getItemIndex();
     int getTotalItens();
};

#endif