#include "network_device.hpp"

int main() {
    NetworkDevice router("192.168.1.1", "Router", true, "TP-Link", 1);
    NetworkDevice laptopDell("192.168.1.10", "Laptop", false, "Dell", 0);
    NetworkDevice laptopHP("192.168.1.15", "Laptop", true, "HP", 1);
    NetworkDevice laptopLenovo("192.168.1.20", "Laptop", false, "Lenovo", 0);
    NetworkDevice laptopAsus("192.168.1.25", "Laptop", true, "Asus", 1);

    router.displayInfo();
    laptopDell.displayInfo();
    laptopHP.displayInfo();
    laptopLenovo.displayInfo();
    laptopAsus.displayInfo();

    return 0;
}
