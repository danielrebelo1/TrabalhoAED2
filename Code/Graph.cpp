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
    double latSourceRad = (coordinatesSource.getLatitude()) * M_PI / 180.0;
    double latDestRad = (coordinatesDest.getLatitude()) * M_PI / 180.0;

    //apply formula
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(latSourceRad) * cos(latDestRad);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

int Graph::getWeight(int src, Edge edge) {
    if(nodes[src].airport.getCode() != edge.airlineCode) return 1;
    return 0;

    /*A medida que vamos metendo novos criterios de pesquisa o peso pode ser diferente. Por exemplo se quisermos o caminho
     * com a menor distãncia absoluta este metodo vai retornar a distancia entre os dois aeroportos usando o metodo harvesine
     * por enquanto apenas queremos o que muda menos vezes de aeroporto. Podemos especificar qual das "pesos" queremos com uma
     * varivael choice que o metodo dijkstra recebe como argumento */

}

void Graph::dijkstra(int src) {
    MinHeap q(n);

    for(int v = 0; v < n; v++){
        nodes[v].dist = INF;            //atributo final da distancia de cada node à source
        q.insert(v, INF);     //criaçao da nossa priority qeue. Valores por default no algoritmo definidos para "Infinito"
        nodes[v].visited = false;
    }

    nodes[src].dist = 0;                 //distancia do node source à source e veidentemente 0
    q.decreaseKey(src, 0);      //aqui a key e evidentemente a propria src e metemos o value a 0 pelo ja explicado
    nodes[src].pred = src;                  //o node antecendente da source e a propria source

    while(q.getSize() > 0){
        int u = q.removeMin();
        nodes[u].visited = true;
        for(Edge edge : nodes[u].adj){
            int v = edge.dest;
            int weight = getWeight(u, edge);
            string airlineUsed = edge.airlineCode;

            if(!nodes[v].visited && (nodes[u].dist + weight) < nodes[v].dist){
                nodes[v].dist = nodes[u].dist + weight;
                q.decreaseKey(v, nodes[v].dist);  //atualizar o valor da distancia para corrigir a sua posicao na minHeap
                nodes[v].pred = u;
                nodes[v].airlineUsed = airlineUsed;
            }

        }
    }

}

list<Node> Graph::dijkstraPathNodes(int a, int b) {
    list<Node> path;
    dijkstra(a);
    if(nodes[b].dist==INF) return path;
    path.push_front(nodes[b]);
    int v = b;
    while (v!=a){
        v=nodes[v].pred;
        path.push_front(nodes[v]);
    }
    return path;
}
