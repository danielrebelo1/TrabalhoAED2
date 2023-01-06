//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iomanip>
#include <iostream>
#include "Manager.h"

class Menu {
public:
    int auxMenu(int maxOption, int minOption);
    int mainMenu();
    int AboutUsMenu();
    int flightMenu();
    int findChoiceMenu();
    std::string findByCode(Manager& manager);
    std::string findbyCity(Manager& manager);
    std::string findbyCountry(Manager& manager);
    int typeInfoChoiceMenu();
    int infoChoiceMenu();
    int nrFlights();
    void menuController(Manager& manager);
    int topAirportsMenu();
    int choiceK();
};


#endif //UNTITLED_MENU_H
