#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Menu.h"


int main() {
    Manager manager;
    manager.init();
    Menu m;
    manager.printAirports(2,1);
    //m.menuController(manager);
    return 0;
}