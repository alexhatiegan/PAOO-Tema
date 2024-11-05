#include "network_device.hpp"

int main() {
    NetworkDevice router("192.168.1.1", "Router", true, "TP-Link");
    NetworkDevice laptopDell("192.168.1.10", "Laptop", false, "Dell");
    NetworkDevice laptopHP("192.168.1.15", "Laptop", true, "HP");
    NetworkDevice laptopLenovo("192.168.1.20", "Laptop", false, "Lenovo");
    NetworkDevice laptopAsus("192.168.1.25", "Laptop", true, "Asus");

    router.displayInfo();
    laptopDell.displayInfo();
    laptopHP.displayInfo();
    laptopLenovo.displayInfo();
    laptopAsus.displayInfo();

    return 0;
}
