#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "Airport.h"


int main() {
    std::ifstream airportsFile , airlinesFile , flightsFile;
    airportsFile.open("Code/dataset/airports.csv");
    airlinesFile.open("Code/dataset/airlines.csv");
    flightsFile.open("Code/dataset/flights.csv");
    FileReader fileReader = FileReader(airportsFile,airlinesFile);
    tabHAirport test = fileReader.readAirportsFile(airportsFile);
    tabHAirline test2 = fileReader.readAirlinesFile(airlinesFile);
    std::cout << test.size() << std::endl;
    std::cout << test2.size() << std::endl;
    return 0;
}
