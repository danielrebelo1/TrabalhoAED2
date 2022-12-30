//
// Created by Jaime on 29/12/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
#include <iostream>
#include "Airport.h"
#include "unordered_map"
#include <vector>
#include <list>
#include <cmath>


struct Edge{
    int dest;
    std::string destName;
    std::string airlineCode;
};

struct Node{
    Airport airport;
    std::list<Edge> adj;
    bool visited;
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
    double harvesine(std::string source, std::string dest);
    std::unordered_map<std::string, int> codeToPos;
    std::unordered_map<int, std::string> posToCode;


};


#endif //UNTITLED_GRAPH_H
