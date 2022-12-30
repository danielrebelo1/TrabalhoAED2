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

    public:
        FileReader();
        tabHAirport readAirportsFile(std::istream &airportFile);
        tabHAirline readAirlinesFile(std::istream &airlineFile);
        void readFlightFile(std::istream &flightFile, Graph &graph);

};


#endif //UNTITLED_FILEREADER_H
