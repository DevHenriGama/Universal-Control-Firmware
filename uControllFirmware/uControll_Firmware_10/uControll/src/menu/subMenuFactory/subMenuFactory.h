#include <iostream>
#include <string>

#include "../../entities/subMenu/subMenu.h"

using namespace std;

class subMenuFactory {
    private:

    public:
    subMenuFactory();

    subMenu* Initial();
    subMenu* SelectConnection();
    subMenu* Bluetooth();
    subMenu* RadioFrequence();
    subMenu* HTTPConnection();
    subMenu* Navigator();
    subMenu* Settings();
    subMenu* ProfileControl();
    subMenu* debug();
    
};
