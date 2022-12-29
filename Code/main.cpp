#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "Airport.h"
#include "Graph.h"


int main() {
    std::ifstream airportsFile , airlinesFile , flightsFile;

    airportsFile.open("C:\\Users\\Jaime\\Desktop\\project-aed\\Code\\dataset\\airports.csv");
    airlinesFile.open("C:\\Users\\Jaime\\Desktop\\project-aed\\Code\\dataset\\airlines.csv");
    flightsFile.open("C:\\Users\\Jaime\\Desktop\\project-aed\\Code\\dataset\\flights.csv");

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

    

    std::cout << test.size() << std::endl;
    std::cout << test2.size() << std::endl;
    return 0;
}
