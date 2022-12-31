//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "FileReader.h"
#include <list>

class Manager {

    tabHAirport airports;
    tabHAirline airlines;
    Graph graph;

public:
    Manager();
    void init();
    tabHAirport getAirports();
    tabHAirline getAirlines();
    Graph getGraph();
    tabHAirport airports_filter_by_country(std::string country);
    tabHAirport airports_filter_by_city(std::string city);
    tabHAirline airlines_filter_by_country(std::string country);


};


#endif //UNTITLED_MANAGER_H
