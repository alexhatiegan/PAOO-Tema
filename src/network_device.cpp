#include "network_device.hpp"
#include <iostream>
using namespace std;

NetworkDevice::NetworkDevice(const string& ip, const string& name, bool online,const string& brand, int code, int latency)
    : ipAddress(ip), deviceName(name), isOnline(online), devicebrand(brand), statusCode(make_unique<int>(code)), Latency(make_shared<int>(latency)) {
    cout << "Constructing NetworkDevice: " << deviceName << " with status code " << *statusCode << " and latency " << *Latency << endl;
}

NetworkDevice::NetworkDevice(const NetworkDevice& other) : ipAddress(other.ipAddress), deviceName(other.deviceName), isOnline(other.isOnline), devicebrand(other.devicebrand), statusCode(make_unique<int>(*other.statusCode)), Latency(other.Latency){
	cout << "Copyng Base NetworkDevice:" << deviceName << endl;
}

NetworkDevice::NetworkDevice(NetworkDevice&& other) : ipAddress(move(other.ipAddress)), deviceName(move(other.deviceName)), isOnline(other.isOnline), devicebrand(move(other.devicebrand)), statusCode(move(other.statusCode)), Latency(move(other.Latency)) {
	cout << "Moving Base NetworkDevice:" << deviceName << endl;
}

NetworkDevice& NetworkDevice::operator=(const NetworkDevice& other){
	if(this != &other) {
		cout << "Copy Operator Base NetworkDevice:" << other.deviceName << endl;
		ipAddress = other.ipAddress;
		deviceName = other.deviceName;
		isOnline = other.isOnline;
		devicebrand = other.devicebrand;
		statusCode = make_unique<int>(*other.statusCode);
		Latency = other.Latency;	
 }
 return *this;
}

NetworkDevice& NetworkDevice::operator=(NetworkDevice&& other){
	if(this != &other) {
		cout << "Moving Operator Base NetworkDevice:" << other.deviceName << endl;
		ipAddress = move(other.ipAddress);
		deviceName = move(other.deviceName);
		isOnline = other.isOnline;
		devicebrand = move(other.devicebrand);
		statusCode = move(other.statusCode);
		Latency = move(other.Latency);	
 }
 return *this;
}


NetworkDevice::~NetworkDevice() {
    Lock lock(&mutx);
    cout << "Destructing: " << deviceName << " with IP " << ipAddress << endl;
}

void NetworkDevice::displayInfo() const {
    if(statusCode){
    cout << "Device: " << deviceName << ", IP: " << ipAddress
         << ", Status: " << (isOnline ? "Online" : "Offline") 
         << ", Brand: " << (devicebrand) << ", Status Code: " << *statusCode << ", Latency: " << *Latency << " ms" << endl;
         } else {
         	cout << "Device is now empty" << endl;
         }
}

SecurityDevice::SecurityDevice(const string& ip, const string& name, bool online,const string& brand, int code, const string& security, int latency)
    : NetworkDevice(ip, name, online, brand, code), adsecurity(security) {
 
    cout << "Constructing Derived SecurityDevice: " << deviceName << " with " << adsecurity << endl;
}

SecurityDevice::SecurityDevice(const SecurityDevice& other) : NetworkDevice(other), adsecurity(other.adsecurity) {

	cout << "Copying Derived SecurityDevice:" << deviceName << " with " << adsecurity << endl;
}

SecurityDevice::SecurityDevice(SecurityDevice&& other) : NetworkDevice(move(other)), adsecurity(move(other.adsecurity)) {

	cout << "Moving Derived SecurityDevice:" << deviceName << " with " << adsecurity << endl;
}

SecurityDevice& SecurityDevice::operator=(const SecurityDevice& other){
	if(this != &other) {
		cout << "Copy Operator Derived NetworkDevice:" << other.deviceName << endl;
		NetworkDevice::operator=(other);
		adsecurity = other.adsecurity;
			
 }
 return *this;
}


SecurityDevice& SecurityDevice::operator=(SecurityDevice&& other){
	if(this != &other) {
		cout << "Moving Operator Derived NetworkDevice:" << other.deviceName << endl;
		NetworkDevice::operator=(move(other));
		adsecurity = move(other.adsecurity);	
 }
 return *this;
}


SecurityDevice::~SecurityDevice() {
    cout << "Destructing SecurityDevice: " << deviceName << endl;
}

void SecurityDevice::displayInfo() const {
    NetworkDevice::displayInfo();
    cout << "Security: " << adsecurity << endl;
}



