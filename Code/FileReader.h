//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include <unordered_set>
#include "Airport.h"
#include "Airline.h"
#include "Graph.h"
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>
#include "Flight.h"

class FileReader {

    private:
       tabHAirport airports;
       tabHAirline airlines;

    public:
        FileReader(std::istream &airportFile, std::istream &airlineFile);
        tabHAirport readAirportsFile(std::istream &airportFile);
        tabHAirline readAirlinesFile(std::istream &airlineFile);
        void readFlightFile(std::istream &flightFile, Graph &graph);

};


#endif //UNTITLED_FILEREADER_H
