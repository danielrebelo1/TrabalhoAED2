//
// Created by Daniel Rebelo on 30/12/2022.
//

#include <fstream>
#include "Manager.h"
using namespace std;

Manager::Manager() {}

void Manager::init() {
    std::ifstream airportsFile , airlinesFile , flightsFile;

    airportsFile.open("Code/dataset/airports.csv");
    airlinesFile.open("Code/dataset/airlines.csv");
    flightsFile.open("Code/dataset/flights.csv");
    FileReader fileReader;

    airports = fileReader.readAirportsFile(airportsFile);
    airlines = fileReader.readAirlinesFile(airlinesFile);
    int numAirports = airports.size();
    graph = Graph(numAirports, true);
    int index = 0;
    for(const Airport &airport : airports){
        graph.addNode(airport);
        graph.codeToPos[airport.getCode()] = index;
        graph.posToCode[index] = airport.getCode();
        index++;
    }
    fileReader.readFlightFile(flightsFile, graph);

    list<Node> list = graph.dijkstraPathNodes(2,0);
}

tabHAirport Manager::getAirports(){
    return airports;
}

tabHAirport Manager::airports_filter_by_country(std::string country){
    tabHAirport airportsCountry;
    for (Airport airport : airports){
        if (airport.getLocation().getCountry() == country){
            airportsCountry.insert(airport);
        }
    }
    return airportsCountry;
}

tabHAirport Manager::airports_filter_by_city(std::string city){
    tabHAirport airportsCity;
    for (Airport airport : airports){
        if (airport.getLocation().getCity() == city){
            airportsCity.insert(airport);
        }
    }
    return airportsCity;
}

tabHAirline Manager::airlines_filter_by_country(std::string country){
    tabHAirline airlinesCountry;
    for (Airline airline : airlines){
        if ( airline.getLocation().getCountry() == country){
            airlinesCountry.insert(airline);
        }
    }
    return airlinesCountry;
}

string Manager::airportWithMostConnections(){
    tabHAirport airportMC;
    return graph.getMaxConnections();
}

tabHAirline Manager::getAirlines(){
    return airlines;
}
Graph Manager::getGraph(){
    return graph;
}