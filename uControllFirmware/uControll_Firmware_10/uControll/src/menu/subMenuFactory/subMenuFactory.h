#include <iostream>
#include "../../entities/subMenu/subMenu.h"

using namespace std;

class subMenuFactory {
    private:

    public:
    subMenuFactory();

    subMenu Initial();
    subMenu Bluetooth();
    subMenu RadioFrequence();
    subMenu WebServer();
    subMenu Navigator();
    subMenu Settings();
    subMenu ProfileControl();
    subMenu debug();
};
