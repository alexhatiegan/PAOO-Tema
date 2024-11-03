#include "network_device.hpp"

int main() {
    NetworkDevice router("192.168.1.1", "Router", true);
    NetworkDevice laptop("192.168.1.10", "Laptop", false);

    router.displayInfo();
    laptop.displayInfo();

    return 0;
}
