#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Menu.h"


int main() {
    Manager manager;
    manager.init();

    manager.cityReport("Lisbon");
    return 0;
}
