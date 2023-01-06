//
// Created by Daniel Rebelo on 30/12/2022.
//

#include <fstream>
#include <algorithm>
#include <set>
#include <map>
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
        it = find_if(it,airports.end(),[&country, this]
                (auto p) {return tolowerString(p.second.getLocation().getCountry()) == tolowerString(country);});
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
        it = find_if(it,airports.end(),[&city,this]
        (auto p) {return tolowerString(p.second.getLocation().getCity()) == tolowerString(city);});
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

airlineMap Manager::airlines_filter_by_airport(std::string airportCode){
    airlineMap am;
    if (checkAirportExists(airportCode)){
    set<string> s = graph.getAirlinesAirport(airportCode);
    for (string str : s){
        am.insert({str,airlines.at(str)});
    }
    }
    return am;
}


void Manager::airportWithMostConnections(int opt, string country){
    string code = graph.getMaxConnections(opt, country);// podemos também retornar o aeroporto fazendo simplesmente airportMap[code]
    cout << "The airport with the most connections is " << airports.at(code).getName() << " from " << airports.at(code).getLocation().getCity() << "," << airports.at(code).getLocation().getCountry() << "." << endl;
}

int Manager::getDepartures(std::string airportCode){
    return graph.getDeparturesAirport(airportCode);
}

int Manager::getArrivals(std::string airportCode){
    return graph.getArrivalsAirport(airportCode);
}

int Manager::getNumberFlights(std::string airportCode){
    return getDepartures(airportCode) + getArrivals(airportCode);
}

int Manager::getNumberAirlinesAirport(std::string airportCode){
    return graph.calculateAirlinesAirport(airportCode);
}

int Manager::getNumberDestinations(std::string airportCode){
    return graph.getNrDestinations(airportCode);
}

int Manager::getNumberDestinationsCountries(std::string airportCode){
    return graph.getNrDestinationsCountries(airportCode);
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
        nrDepartures += graph.getDeparturesAirport(p.second.getCode());
    }
    cout << "Number of departures in " << country << ": " << nrDepartures;
    return;
}

void Manager::calculateFlightsAirline(std::string airlineCode){
    cout << "This airline has " << graph.getFlightsAirline(airlineCode) << " flights";
    return;
}

bool Manager::checkAirportExists(std::string airportCode) {
    try {
        airports.at(airportCode);
    }
    catch (exception e) {
        cout << endl << "No airport with that code. Try again: ";
        return false;
    }
    return true;
}

bool Manager::checkAirlineExists(std::string airlineCode) {
    try {
        airlines.at(airlineCode);
    }
    catch (exception e) {
        cout << "No airline with such code.Please try again" << endl;
        return false;
    }
    return true;
}

bool Manager::checkCountryExists(std::string country) {
    auto it = std::find_if(airports.begin(), airports.end(),[&country, this](pair<string,Airport> ap){return tolowerString(ap.second.getLocation().getCountry()) == tolowerString(country);});
    if (it == airports.end()){ cout << "No such country in database." << endl; return false;}
    return true;
}

string Manager::tolowerString(string s){
    string newstr;
    for (auto c : s){
        newstr.push_back(tolower(c));
    }
    return newstr;
}

bool Manager::checkCityExists(std::string city) {
    tolowerString(city);
    auto it = std::find_if(airports.begin(), airports.end(),[&city, this](pair<string,Airport> ap){
        return tolowerString(ap.second.getLocation().getCity()) == tolowerString(city);
    });
    if (it == airports.end()){ cout << "No such city in database." << endl; return false;}
    return true;
}


void Manager::airportReport(std::string airportCode) {
    if (checkAirportExists(airportCode)){
        Airport airport = airports.at(airportCode);
        cout << endl << "The " << airport.getName() << " airport is an international airport in " << airport.getLocation().getCity() << "," << airport.getLocation().getCountry() << "." << endl;
        cout << "This airport has " << getNumberFlights(airportCode) << " flights , " << getDepartures(airportCode) <<" of these are departures and " <<
        getArrivals(airportCode) << " are arrivals, to " << getNumberDestinations(airportCode)
        << " cities in " << getNumberDestinationsCountries(airportCode) << " countries." << endl;
        cout << "On top of that, there exists " << getNumberAirlinesAirport(airportCode) << " airlines operating in it." << endl;
        cout << "Do you wish to list all airlines operating on this airport?(Y/n): ";
        string input;
        cin >> input;
        while (tolowerString(input) != "n" && tolowerString(input) != "y") {
            cout << "Enter a valid response: Y for yes or N for no (not case sensitive):  " << endl;
            cin >> input;
        }
        if (tolowerString(input) == "n") return;
        cout << "These are: " << endl;
        airlineMap am = airlines_filter_by_airport(airportCode);
        int x = 0;
        cout << setw(30) << "Airline" << setw(30) << "Country" << endl;
        for (auto p : am){
            cout << ++x << ". " << setw(30) << p.second.getName() << setw(30) << p.second.getLocation().getCountry() << endl;
        }
        cout << endl << "Press Enter to continue.\n";
        system("pause > nul");
    }
}

void Manager::cityReport(std::string city){
    if (checkCityExists(city)){
        airportMap am = airports_filter_by_city(city);
        cout << "The beautiful city of " << city << " in " << am.begin()->second.getLocation().getCountry() << " has " << am.size() << " airports." << endl;
        cout << "These are:" << endl;
        map<int,string> m;
        int x = 1;
        for (auto p : am){
            cout << x << ". " << p.second.getName() << endl;
            m.insert({x,p.second.getCode()});
        }

        cout << "Enter the airport number above for an airport report or enter 0 to leave this menu: ";
        int input;
        cin >> input;
        while (input > m.size()) {
            cout << "Index not valid.Try again: " << endl;
            cin >> input;
        }
        if (input == 0) return;
        airportReport(m.at(input));
    }

}

void Manager::printPath(vector<Node> airports) {
    for(Node node : airports){
        cout << node.airport.getCode() << " " << node.airport.getName() << "\n";
        if(node.airlineUsed != "")
           cout << "Using airline: " << node.airlineUsed << "(" << airlines.at(node.airlineUsed).getName()
                << ")" << ", you go to" << "\n";
    }
}
int Manager::getConnectedComponents() {
    return graph.dfs_cc();
}

int Manager::getArticulationPoints() {
    return (int)graph.getArticulationPoints().size();
}

void Manager::printAirports(int k,int opt){
    vector<pair<string,int>> v;
    switch(opt){
        case 1:
        {
            for (pair<string,Airport> pa : airports){
                v.push_back(make_pair(pa.second.getCode(), getNumberAirlinesAirport(pa.second.getCode())));
            }
            sort(v.begin(),v.end(),[] ( pair<string,int> &p1 , pair<string,int> &p2) {return p1.second > p2.second;});
            v.resize(k);
            int i = 1;
            cout << endl;
            for (auto elem : v){
                Airport a = airports.at(elem.first);
                cout << i++ << ". " << a.getName() << " - " << elem.second << " - " << a.getLocation().getCity() << " - " << a.getLocation().getCountry() << endl;
            }
            cout << endl << "Press Enter to continue.\n";
            system("pause > nul");
            break;
        }
        case 2:
            break;
    }

}