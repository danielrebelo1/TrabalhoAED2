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
    airportMap = fileReader.readAirportsFile2(airportsFile);
    // airlines = fileReader.readAirlinesFile(airlinesFile);
    airlineMap = fileReader.readAirlinesFile2(airlinesFile);
    int numAirports = airportMap.size();
    graph = Graph(numAirports, true);
    int index = 0;

    for(pair<std::string,Airport> p : airportMap){
        graph.addNode(p.second);
        graph.codeToPos[p.second.getCode()] = index;
        graph.posToCode[index] = p.second.getCode();
        index++;
    }
    fileReader.readFlightFile(flightsFile, graph);

    std::list<Node> list = graph.dijkstraPathNodes(2,4 , 1);
    std::list<Node> list2 = graph.dijkstraPathNodes(2,4,2);
}

tabHAirport Manager::getAirports(){
    return airports;
}
tabHAirline Manager::getAirlines(){
    return airlines;
}
Graph Manager::getGraph(){
    return graph;
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

std::unordered_map<std::string,Airport> Manager::airports_filter_by_country2(std::string country){
    std::unordered_map<string,Airport> airportsCountry;
    auto it = airportMap.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airportMap.end(),[&country]
                (auto p) {return p.second.getLocation().getCountry() == country;});
        if (it != airportMap.end()){
            airportsCountry.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
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


std::unordered_map<std::string,Airport> Manager::airports_filter_by_city2(std::string city){
    std::unordered_map<std::string,Airport> airportsCity;
    auto it = airportMap.begin();
    bool noMoreFound = true;
    while (noMoreFound){
        it = find_if(it,airportMap.end(),[&city]
        (auto p) {return p.second.getLocation().getCity() == city;});
        if (it != airportMap.end()){
            airportsCity.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airportsCity;
}

std::unordered_map<std::string,Airline> Manager::airlines_filter_by_country(std::string country){
    std::unordered_map<std::string,Airline> airlinesCountry;
    bool noMoreFound = true;
    auto it = airlineMap.begin();
    while (noMoreFound){
        it = find_if(it,airlineMap.end(),[&country]
                (auto p) {return p.second.getLocation().getCountry() == country;});
        if (it != airlineMap.end()){
            airlinesCountry.insert(*it);
            it++;
        }
        else{
            noMoreFound = false;
        }
    }
    return airlinesCountry;
}

string Manager::airportWithMostConnections(){
    return graph.getMaxConnections(); // podemos também retornar o aeroporto fazendo simplesmente airportMap[code]
}
