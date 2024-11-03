#include "network_device.hpp"
#include <iostream>
using namespace std;

NetworkDevice::NetworkDevice(const string& ip, const string& name, bool online)
    : ipAddress(ip), deviceName(name), isOnline(online) {
    
}

void NetworkDevice::displayInfo() {
    cout << "Device: " << deviceName << ", IP: " << ipAddress
         << ", Status: " << (isOnline ? "Online" : "Offline") 
         << "\n";
}
