//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include <unordered_set>
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>

#include "Airline.h"
#include "Graph.h"
#include "Flight.h"
#include "Airport.h"

class FileReader {

    private:

       tabHAirport airports;
       tabHAirline airlines;
       std::unordered_map<std::string,Airport> airports2;
       std::unordered_map<std::string,Airline> airlineMap;

    public:
        FileReader();
        tabHAirport readAirportsFile(std::istream &airportFile);
        tabHAirline readAirlinesFile(std::istream &airlineFile);
        void readFlightFile(std::istream &flightFile, Graph &graph);
        std::unordered_map<std::string,Airport> readAirportsFile2(std::istream &airportFile);
        std::unordered_map<std::string,Airline> readAirlinesFile2(std::istream &airlinesFile);

};


#endif //UNTITLED_FILEREADER_H
