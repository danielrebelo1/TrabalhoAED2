//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "FileReader.h"
#include <list>

class Manager {

    airportMap airports;
    airlineMap airlines;
    Graph graph;

public:
    Manager();
    void init();
    airportMap getAirports();
    airlineMap getAirlines();
    Graph getGraph();
    airportMap airports_filter_by_country(std::string country);
    airportMap airports_filter_by_city(std::string city);
    airlineMap airlines_filter_by_country(std::string country);
    void airportWithMostConnections(int opt, std::string country);
    void getNumberFlights(std::string &airportCode);
    void getNumberAirlines(std::string &airportCode);
    void getNumberDestinations(std::string &airportCode);
    void getNumberDestinationsCountries(std::string airportCode);
    void calculateGlobalStatsNetwork();
    void calculateDeparturesCountry(std::string country);
    void calculateFlightsAirline(std::string airlineCode);
    void getNumberAirlinesAirport(std::string airportCode);
    bool checkAirportExists(std::string airportCode);
    bool checkAirlineExists(std::string airlineCode);

};


#endif //UNTITLED_MANAGER_H
