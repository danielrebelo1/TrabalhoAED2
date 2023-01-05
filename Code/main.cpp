#include <iostream>
#include <fstream>

#include "Manager.h"
#include "AuxiliarFunctions.h"


int main() {
    Manager manager;
    manager.init();
    manager.airports_filter_by_city("Paris");
    return 0;
}
