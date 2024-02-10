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
        string tag;
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
     string getItem();
     string getTag();
     void setTag(string aTag);
     
};

#endif