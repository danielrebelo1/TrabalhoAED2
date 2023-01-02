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
#include <list>
#include <cmath>
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
    void addNode(Airport airport);
    double haversine(std::string source, std::string dest);
    void dijkstra(int src, int opt);
    std::list<Node> dijkstraPathNodes(int a, int b, int opt);
    std::unordered_map<std::string, int> codeToPos;
    std::unordered_map<int, std::string> posToCode;
    int getWeight(int src, Edge edge, int opt);

};


#endif //UNTITLED_GRAPH_H
