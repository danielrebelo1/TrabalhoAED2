#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "Airport.h"
#include "Graph.h"


int main() {
    std::ifstream airportsFile , airlinesFile , flightsFile;

    airportsFile.open("Code/dataset/airports.csv");
    airlinesFile.open("Code/dataset/airlines.csv");
    flightsFile.open("Code/dataset/flights.csv");

    FileReader fileReader = FileReader(airportsFile,airlinesFile);

    tabHAirport test = fileReader.readAirportsFile(airportsFile);
    tabHAirline test2 = fileReader.readAirlinesFile(airlinesFile);

    int numAirports = test.size();
    Graph graph = Graph(numAirports, true);

    int index = 0;
    for(const Airport &airport : test){
        graph.addNode(airport);
        graph.codeToPos[airport.getCode()] = index;
        graph.posToCode[index] = airport.getCode();
        index++;
    }

    fileReader.readFlightFile(flightsFile, graph);
    double testHarvesine = graph.harvesine("CDG", "LGA");
    
    std::cout << testHarvesine << "\n";
    std::cout << test.size() << std::endl;
    std::cout << test2.size() << std::endl;
    return 0;
}
