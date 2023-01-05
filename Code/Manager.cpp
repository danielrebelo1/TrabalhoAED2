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

    vector<string> list = graph.bfs(2, 4);
    std::list<Node> list2 = graph.dijkstraPathNodes(2,4);
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
    if (airlinesCountry.empty()) { cout << "There are no airlines from the selected country;" << endl; return airlinesCountry; };
    cout << "There are " << airlinesCountry.size() << " airlines from " << country << endl;
    cout << "These are:" << endl;
    int x = 0;
    for (auto a : airlinesCountry){
        cout << ++x << ". " << a.second.getName() << "    " << a.second.getLocation().getCity() << endl;
    }
    return airlinesCountry;
}

void Manager::airportWithMostConnections(int opt, string country){
    string code = graph.getMaxConnections(opt, country);// podemos também retornar o aeroporto fazendo simplesmente airportMap[code]
    cout << "The airport with the most connections is " << airports.at(code).getName() << " from " << airports.at(code).getLocation().getCity() << "," << airports.at(code).getLocation().getCountry() << "." << endl;
}

void Manager::getNumberFlights(std::string &airportCode){
    cout << "This airport has " << graph.getFlightsAirport(airportCode) << " flights";
    return;
}

void Manager::getNumberAirlines(std::string &airportCode){
    cout << "There are " << graph.getNrAirlines(airportCode) << " airlines operating on this airport";
    return;
}

void Manager::getNumberDestinations(std::string &airportCode){
    cout << airports.at(airportCode).getName() << " has connections to " << graph.getNrDestinations(airportCode) << " cities";
}
void Manager::getNumberDestinationsCountries(std::string airportCode){
    cout  << airports.at(airportCode).getName() << " has connections to " << graph.getNrDestinationsCountries(airportCode) << " countries";
}

void Manager::calculateGlobalStatsNetwork(){
    int nrAirports = airports.size() , nrFlights = graph.getNrTotalFlights() , nrAirlines = airlines.size();
    cout << "This network consists of " << nrAirports << " airports , " << nrAirlines << " airlines and " << nrFlights  << " flights." << endl;
    return;
}

void Manager::calculateDeparturesCountry(std::string country){
    int nrDepartures = 0;
    airportMap am = airports_filter_by_country(country);
    if (am.empty()) {cout << "No airports in that country" << endl;}
    for (auto p : am){
        nrDepartures += graph.getFlightsAirport(p.second.getCode());
    }
    cout << "Number of departures in " << country << ": " << nrDepartures;
    return;
}

void Manager::calculateFlightsAirline(std::string airlineCode){
    cout << "This airline has " << graph.getFlightsAirline(airlineCode) << " flights";
    return;
}

void Manager::getNumberAirlinesAirport(std::string airportCode) {
    cout << "This airline operates in " << graph.calculateAirlinesAirport(airportCode) << " airports";
    return;
}

bool Manager::checkAirportExists(std::string airportCode) {
    try {
        airports.at(airportCode);
    }
    catch (exception e) {
        cout << "No airport with such code." << endl;
        return false;
    }
    return true;
}

bool Manager::checkAirlineExists(std::string airlineCode) {
    try {
        airlines.at(airlineCode);
    }
    catch (exception e) {
        cout << "No airline with such code." << endl;
        return false;
    }
    return true;
}