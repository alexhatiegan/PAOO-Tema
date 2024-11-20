#include "network_device.hpp"

int main() {
    NetworkDevice router("192.168.1.1", "Router", true, "TP-Link", 1);
    NetworkDevice laptopDell("192.168.1.10", "Laptop", false, "Dell", 0);
    NetworkDevice laptopHP("192.168.1.15", "Laptop", true, "HP", 1);
    router.displayInfo();
    laptopDell.displayInfo();
    laptopHP.displayInfo();
    
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    
    cout << "Copy Base Constructor:\n";
    NetworkDevice cpRouter(router);
    cpRouter.displayInfo();
    router.displayInfo();
    
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    
    cout << "Move base Constructor\n";
    NetworkDevice mvLaptop(move(laptopHP));
    mvLaptop.displayInfo();
    cout<< "After:\n";
    laptopHP.displayInfo();
    
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Copy Base Assignment Operator:\n";
    NetworkDevice asgRouter("192.168.1.20", "TemporaryRouter", false, "Default", 0);
    cout << "Before:\n";
    asgRouter.displayInfo();
    asgRouter = router; 
    cout << "After:\n";
    asgRouter.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Move Base Assignment Operator:\n";
    NetworkDevice asgmvDevice("192.168.1.30", "TemporaryDevice", false, "Default", 0);
    cout << "Before:\n";
    asgmvDevice.displayInfo();
    asgmvDevice = move(mvLaptop); 
    cout << "After:\n";
    asgmvDevice.displayInfo();
    cout << "Source after:\n";
    mvLaptop.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "SecurityDevice:\n";
    SecurityDevice firewall("192.168.1.100", "FortiManager", true, "FortiGate", 2, "Secured Internet");
    firewall.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Copy Derived Constructor:\n";
    SecurityDevice cpFirewall(firewall); 
    cpFirewall.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Move Derived Constructor:\n";
    SecurityDevice mvFirewall(move(firewall)); 
    mvFirewall.displayInfo();
    cout << "After:\n";
    firewall.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Copy Derived Assignment Operator:\n";
    SecurityDevice assignedFirewall("192.168.1.200", "FortiAnalyzer", false, "FortiGate", 3, "Backup");
    cout << "Before:\n";
    assignedFirewall.displayInfo();
    assignedFirewall = cpFirewall; 
    cout << "After:\n";
    assignedFirewall.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "Move Derived Assignment Operator:\n";
    SecurityDevice assignedMovedFirewall("192.168.1.250", "Temporary", false, "Default", 0, "None");
    cout << "Before:\n";
    assignedMovedFirewall.displayInfo();
    assignedMovedFirewall = move(mvFirewall);
    cout << "After:\n";
    assignedMovedFirewall.displayInfo();
    cout << "Source after:\n";
    mvFirewall.displayInfo();

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    
    
    return 0;
}
