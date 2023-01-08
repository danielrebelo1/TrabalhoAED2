//
// Created by Daniel Rebelo on 30/12/2022.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "FileReader.h"
#include <list>
#include <iomanip>

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
    std::string get_airport_by_country(std::string country);
    airportMap airports_filter_by_country(std::string country);
    airportMap airports_filter_by_city(std::string city);
    airlineMap airlines_filter_by_country(std::string country);
    airlineMap airlines_filter_by_airport(std::string airportCode);
    void airportWithMostConnections(int opt, std::string country);
    int getDepartures(std::string airportCode);
    int getArrivals(std::string airportCode);
    int getNumberFlights(std::string airportCode);
    int getNumberAirlinesAirport(std::string airportCode);
    int getNumberDestinations(std::string airportCode);
    int getNumberDestinationsCountries(std::string airportCode);
    int maxFlightsStats(std::string airport, int maxFlights, int opt);
    void calculateGlobalStatsNetwork();
    void calculateDeparturesCountry(std::string country);
    void calculateFlightsAirline(std::string airlineCode);
    bool checkAirportExists(std::string airportCode);
    bool checkAirlineExists(std::string airlineCode);
    bool checkCountryExists(std::string country);
    bool checkCityExists(std::string city);
    void airportReport(std::string airportCode);
    void cityReport(std::string city);
    void printPath(std::vector<Node> airports );
    std::string tolowerString(std::string str);
    int getConnectedComponents();
    int getArticulationPoints();
    void printAirports(int k,int opt);
    void printArticulationPoints();
    void printConnectedComponents();
    bool checkSameAirport(std::string origin, std::string dest);
};


#endif //UNTITLED_MANAGER_H
