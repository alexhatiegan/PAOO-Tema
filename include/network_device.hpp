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
    string devicebrand;
    int* statusCode;
    
public:
    NetworkDevice(const string& ip, const string& name, bool online = false,const string& brand = "", int code = 0);
        
    ~NetworkDevice();
    
    void displayInfo();
};

#endif
