#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Menu.h"


int main() {
    Manager manager;
    manager.init();
    Menu m;
    airportMap m1;
    //manager.airportWithMostConnections(1,"Portugal");
    manager.checkAirlineExists("TAP");
    m.menuController(manager);
    return 0;
}
