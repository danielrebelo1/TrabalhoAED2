//
// Created by Jaime on 29/12/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
#include <iostream>
#include "Airport.h"
#include "MinHeap.h"
#include "unordered_map"
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <set>
#define INF (INT16_MAX/2)

struct Edge{
    int dest;
    std::string destName;
    std::string airlineCode;
};

struct Node{
    Airport airport;
    std::list<Edge> adj;
    bool visited;
    int dist;
    int pred;
    int low;
    int num;
    std::string airlineUsed; //airline que conecta este node ao seu predecessor no algoritmo de dijkstra
};


class Graph {
    int n;
    bool hasDir;
    std::vector<Node> nodes;

public:
    Graph();
    Graph(int nodes, bool dir = false);
    void addEdge(int src, int dest, std::string airlineCode = "");
    void dfs(int v);
    std::vector<Node> bfs(int start, int end);
    std::vector<Node> bfsMD(int start, int maxDistance);
    int dfs_cc();
    void addNode(Airport airport);
    double haversine(std::string source, std::string dest);
    void dijkstra(int src);
    std::vector<Node> dijkstraPathNodes(int a, int b);
    std::unordered_map<std::string, int> codeToPos;
    std::unordered_map<int, std::string> posToCode;
    std::string getMaxConnections(int opt, std::string country = "");
    int getWeight(int src, Edge edge);
    int getDeparturesAirport(std::string code);
    int getNrDestinations(std::string &code);
    int getNrDestinationsCountries(std::string &code);
    int getNrTotalFlights();
    int getFlightsAirline(std::string airlineCode);
    int calculateAirlinesAirport(std::string airportCode);
    int getArrivalsAirport(std::string code);
    std::set<std::string> getAirlinesAirport(std::string airportCode);
    std::vector<int> getArticulationPoints();
    void dfs_articulationPoints(int i,int order,std::vector<int> &vec);
};


#endif //UNTITLED_GRAPH_H
