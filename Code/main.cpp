#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Menu.h"


int main() {
    Manager manager;
    manager.init();
    Menu m;
    std::cout << manager.getArticulationPoints();
    m.menuController(manager);
    return 0;
}