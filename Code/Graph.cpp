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