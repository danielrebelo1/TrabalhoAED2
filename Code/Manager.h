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
    std::unordered_map<std::string,Airport> airportMap;
    std::unordered_map<std::string,Airline> airlineMap;
    Graph graph;

public:
    Manager();
    void init();
    tabHAirport getAirports();
    tabHAirline getAirlines();
    Graph getGraph();
    tabHAirport airports_filter_by_country(std::string country);
    std::unordered_map<std::string,Airport> airports_filter_by_country2(std::string country);
    tabHAirport airports_filter_by_city(std::string city);
    std::unordered_map<std::string,Airport> airports_filter_by_city2(std::string city);
    std::unordered_map<std::string,Airline> airlines_filter_by_country(std::string country);
    std::string airportWithMostConnections();
};


#endif //UNTITLED_MANAGER_H
