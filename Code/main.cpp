#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    std::string city;
    std::cin >> city;
    airportMap am = manager.airports_filter_by_city(city);
    return 0;
}
