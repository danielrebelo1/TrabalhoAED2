#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Menu.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    Menu m;
    //manager.airportWithMostConnections(1,"Portugal");
    manager.checkAirlineExists("TAP");
    m.menuController();
    return 0;
}
