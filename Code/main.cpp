#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    // std::cout << manager.airportWithMostConnections();
    manager.airlines_filter_by_country("France");
    return 0;
}
