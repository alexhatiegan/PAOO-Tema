#ifndef NETWORK_DEVICE_HPP
#define NETWORK_DEVICE_HPP
#include <iostream>
#include <string>
using namespace std;

class NetworkDevice {
private:
    string ipAddress;
    string deviceName;
    bool isOnline;
    
public:
    NetworkDevice(const string& ip, const string& name, bool online = false);
        

    void displayInfo();
};

#endif
