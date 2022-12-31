#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    std::cout << manager.airportWithMostConnections();
    return 0;
}
