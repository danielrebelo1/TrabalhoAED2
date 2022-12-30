//
// Created by Jaime on 29/12/2022.
//

#include "Graph.h"
using namespace std;

Graph::Graph() {}

Graph::Graph(int nodes, bool dir) {
    this->n = nodes;
    this->hasDir = dir;
}

void Graph::addNode(Airport airport) {
    nodes.push_back(Node{airport});
}

void Graph::addEdge(int src, int dest, std::string airlineCode) {
    nodes[src].adj.push_back(Edge{dest, posToCode[dest],airlineCode});
}

double Graph::haversine(string source, string dest) {
    Coordinates coordinatesSource = nodes[codeToPos[source]].airport.getCoordinates();
    Coordinates coordinatesDest = nodes[codeToPos[dest]].airport.getCoordinates();

    //distance between latitudes and longitudes
    double dLat = (coordinatesDest.getLatitude() - coordinatesSource.getLatitude()) *
                    M_PI / 180.0;
    double dLon = (coordinatesDest.getLongitude() - coordinatesSource.getLongitude()) *
                    M_PI / 180.0;

    //convert to radians
    double latSourceRad = (coordinatesSource.getLatitude()) * M_PI/ 180.0;
    double latDestRad = (coordinatesDest.getLatitude()) * M_PI / 180.0;

    //apply formula
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(latSourceRad) * cos(latDestRad);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;

}
