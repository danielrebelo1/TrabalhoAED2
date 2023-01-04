//
// Created by Daniel Rebelo on 30/12/2022.
//

#include <fstream>
#include <algorithm>
#include "Manager.h"
using namespace std;

Manager::Manager() {}

void Manager::init() {
    std::ifstream airportsFile , airlinesFile , flightsFile;

    airportsFile.open("Code/dataset/airports.csv");
    airlinesFile.open("Code/dataset/airlines.csv");
    flightsFile.open("Code/dataset/flights.csv");
    FileReader fileReader;

    // airports = fileReader.readAirportsFile(airportsFile);
    airports = fileReader.readAirportsFile(airportsFile);
    // airlines = fileReader.readAirlinesFile(airlinesFile);
    airlines = fileReader.readAirlinesFile(airlinesFile);
    int numAirports = airports.size();
    graph = Graph(numAirports, true);
    int index = 0;

    for(pair<std::string,Airport> p : airports){
        graph.addNode(p.second);
        graph.codeToPos[p.second.getCode()] = index;
        graph.posToCode[index] = p.second.getCode();
        index++;
    }
    fileReader.readFlightFile(flightsFile, graph);

    std::list<Node> list = graph.dijkstraPathNodes(2,4 , 1);
    std::list<Node> list2 = graph.dijkstraPathNodes(2,4,2);
}

airportMap Manager::getAirports(){
    return airports;
}
airlineMap Manager::getAirlines(){
    return airlines;
}
Graph Manager::getGraph(){
    return graph;
}

airportMap Manager::airports_filter_by_country(std::string country){
    airportMap airportsCountry;
    auto it = airports.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airports.end(),[&country]
                (auto p) {return p.second.getLocation().getCountry() == country;});
        if (it != airports.end()){
            airportsCountry.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airportsCountry;
}


airportMap Manager::airports_filter_by_city(std::string city){
    airportMap airportsCity;
    auto it = airports.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airports.end(),[&city]
        (auto p) {return p.second.getLocation().getCity() == city;});
        if (it != airports.end()){
            airportsCity.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airportsCity;
}

airlineMap Manager::airlines_filter_by_country(std::string country){
    airlineMap airlinesCountry;
    bool noMoreFound = true;
    auto it = airlines.begin();
    while (noMoreFound){
        it = find_if(it,airlines.end(),[&country]
                (auto p) {return p.second.getLocation().getCountry() == country;});
        if (it != airlines.end()){
            airlinesCountry.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airlinesCountry;
}

string Manager::airportWithMostConnections(int opt, string country){
    return graph.getMaxConnections(opt, country); // podemos também retornar o aeroporto fazendo simplesmente airportMap[code]
}

int Manager::getNumberFlights(std::string &airportCode){
    return graph.getFlights(airportCode);
}

int Manager::getNumberAirlines(std::string &airportCode){
    return graph.getNrAirlines(airportCode);
}

int Manager::getNumberDestinations(std::string &airportCode){
    return graph.getNrDestinations(airportCode);
}
int Manager::getNumberDestinationsCountries(std::string airportCode){
    return graph.getNrDestinationsCountries(airportCode);
}

std::vector<int> Manager::calculateGlobalStatsNetwork(){
    int nrAirports = airports.size() , nrFlights = 0 , nrAirlines = airlines.size();
    vector<int> v;
    return v;
}