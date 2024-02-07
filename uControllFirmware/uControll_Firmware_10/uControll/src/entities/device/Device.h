#ifndef Device_h
#define Device_h

#include <string>

using namespace std;

class Device {

    private:
        string name;
        string address;             

    public:
        Device();
        void setName(string aName);
        string getName();
        void setAddress(string aAddress);
        string getAddress();

};

#endif