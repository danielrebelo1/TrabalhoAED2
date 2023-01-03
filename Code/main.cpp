#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    // std::cout << manager.airportWithMostConnections();
    // airlineMap a = manager.airlines_filter_by_country("France");
    // std::cout << manager.getAirports().size() << "    " << manager.getAirlines().size() << "  " << a.size() << std::endl;
    //std::string x = manager.airportWithMostConnections(1,"Italy");
    std::cout << manager.getNumberDestinationsCountries("VIL");
    return 0;
}
