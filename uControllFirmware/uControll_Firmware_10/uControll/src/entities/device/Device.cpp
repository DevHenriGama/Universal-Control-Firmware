#include "Device.h"
#include <string>

using namespace std;

Device::Device(){
    name = "";
    address = "";
};

void Device::setName(string aName){
    name = aName;
};

string Device::getName(){
    return name;
};

void Device::setAddress(string aAddress){
    address = aAddress;
};

string Device::getAddress(){
    return address;
};