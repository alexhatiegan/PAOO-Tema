#ifndef NETWORK_DEVICE_HPP
#define NETWORK_DEVICE_HPP
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
using namespace std;

class Lock {
public:
    explicit Lock(mutex *pm) : mutexPtr(pm) {
            mutexPtr->lock();
    }

    ~Lock() {
            mutexPtr->unlock();
    }

private:
    mutex* mutexPtr;
};

class NetworkDevice {
protected:
    string ipAddress;
    string deviceName;
    bool isOnline;
    string devicebrand;
    unique_ptr<int> statusCode;
    shared_ptr<int> Latency; 
    mutex mutx;
    
public:
    NetworkDevice(const string& ip, const string& name, bool online = false,const string& brand = "", int code = 0, int latency = 0);
    
    NetworkDevice(const NetworkDevice& other);
    
    NetworkDevice(NetworkDevice&& other);
    
    NetworkDevice& operator=(const NetworkDevice& other);
    
    NetworkDevice& operator=(NetworkDevice&& other);
    
    virtual ~NetworkDevice();
    
    void displayInfo() const;
    
    //NetworkDevice(const NetworkDevice& other) = delete;
    
    //NetworkDevice& operator=(const NetworkDevice& other) = delete;
    
};

class SecurityDevice : public NetworkDevice {
private:
	string adsecurity;
public:
    SecurityDevice(const string& ip, const string& name, bool online,const string& brand, int code, const string& security, int latency = 0);
    
    SecurityDevice(const SecurityDevice& other);
    
    SecurityDevice(SecurityDevice&& other);
    
    SecurityDevice& operator=(const SecurityDevice& other);
    
    SecurityDevice& operator=(SecurityDevice&& other);
    
    ~SecurityDevice();
    
    void displayInfo() const;
    
    // SecurityDevice(const SecurityDevice& other) = delete;
    
    //SecurityDevice& operator=(const SecurityDevice& other) = delete;
	
};

#endif
