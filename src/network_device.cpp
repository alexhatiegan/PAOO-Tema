#include "network_device.hpp"
#include <iostream>
using namespace std;

NetworkDevice::NetworkDevice(const string& ip, const string& name, bool online,const string& brand, int code)
    : ipAddress(ip), deviceName(name), isOnline(online), devicebrand(brand) {
    
    statusCode = new int(code);

    cout << "Constructing NetworkDevice: " << deviceName << " with status code " << *statusCode << endl;
}

NetworkDevice::~NetworkDevice() {
    delete statusCode; 
    cout << "Destructing NetworkDevice: " << deviceName << " with IP " << ipAddress << endl;
}

void NetworkDevice::displayInfo() {
    cout << "Device: " << deviceName << ", IP: " << ipAddress
         << ", Status: " << (isOnline ? "Online" : "Offline") 
         << ", Brand: " << (devicebrand) << ", Status Code: " << (*statusCode) << "\n";
}
