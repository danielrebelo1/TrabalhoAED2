#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    //manager.airportWithMostConnections(1,"Portugal");
    manager.checkAirlineExists("TAP");
    return 0;
}
