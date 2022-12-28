//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include <unordered_set>
#include "Airport.h"
#include "Airline.h"
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>

class FileReader {

    private:
       std::unordered_set<Airport> airports;

    public:

        FileReader(std::istream &airportFile);

        std::unordered_set<Airport> getAirports() const;

};


#endif //UNTITLED_FILEREADER_H
