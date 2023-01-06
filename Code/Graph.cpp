//
// Created by Jaime on 29/12/2022.
//

#include <algorithm>
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
    return(haversine(posToCode[src], posToCode[edge.dest]));
    return 0;

    /*A medida que vamos metendo novos criterios de pesquisa o peso pode ser diferente. Por exemplo se quisermos o caminho
     * com a menor distãncia absoluta este metodo vai retornar a distancia entre os dois aeroportos usando o metodo harvesine
     * por enquanto apenas queremos o que muda menos vezes de aeroporto. Podemos especificar qual das "pesos" queremos com uma
     * varivael choice que o metodo dijkstra recebe como argumento */

}

vector<Node> Graph::bfs(int start, int end) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;

    vector<Node> path;
    queue<int> q; // queue of unvisited nodes
    q.push(start);
    nodes[start]. visited = true;
    nodes[start].dist = 0;


    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u; // set the predecessor of w to be u
                nodes[u].airlineUsed = e.airlineCode;


                if(w == end){
                    int current = end;
                    while(current != start){
                        path.push_back(nodes[current]);
                        current = nodes[current].pred;
                    }
                    path.push_back(nodes[start]);
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
            q.push(w);
        }
    }
    return path;
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
                nodes[u].airlineUsed = airlineUsed;
            }

        }
    }

}

vector<Node> Graph::dijkstraPathNodes(int a, int b) {
    vector<Node> path;
    dijkstra(a);
    if(nodes[b].dist==INF) return path;
    path.push_back(nodes[b]);
    int v = b;
    while (v!=a){
        v=nodes[v].pred;
        path.push_back(nodes[v]);
    }
    reverse(path.begin(), path.end());
    return path;
}

string Graph::getMaxConnections(int opt, string loc){
    int c = 0;
    string code = "";
    if(opt == 1) {                                                   //se quisermos o aeroporto com o maior numero de destinos diferentes
        if (loc == "") {
            for (Node node: nodes) {
                std::unordered_set<std::string> airportCodes;
                for (Edge e: node.adj) {
                    airportCodes.insert(e.destName);
                }
                if (airportCodes.size() > c) {
                    c = airportCodes.size();
                    code = node.airport.getCode();
                }
            }
        } else {
            for (Node node: nodes) {
                std::unordered_set<std::string> airportCodes;
                if (node.airport.getLocation().getCountry() == loc || node.airport.getLocation().getCity() == loc) {
                    for (Edge e: node.adj) {
                        airportCodes.insert(e.destName);
                    }
                    if (airportCodes.size() > c) {
                        c = airportCodes.size();
                        code = node.airport.getCode();
                    }
                }
            }
        }
    }
    else if(opt == 2){                                               //se quisermos o aeroporto com mais voos
        if(loc == ""){
            for(Node &node : nodes){
                if(node.adj.size() > c){
                    c = node.adj.size();
                    code = node.airport.getCode();
                }
            }
        }
        else{
            for(Node node : nodes){
                if(node.airport.getLocation().getCountry() == loc || node.airport.getLocation().getCity() == loc){ // nao sei se é a melhor approach por poderem haver paises c mesmo nome de cidades
                    if(node.adj.size() > c){
                        c = node.adj.size();
                        code = node.airport.getCode();
                    }
                }
            }
        }
    }
    return code;
}


int Graph::getDeparturesAirport(std::string code){
    int pos = codeToPos[code];
    return (int) nodes[pos].adj.size();
}


int Graph::calculateAirlinesAirport(std::string airportCode){
    set<string> aa;
    int pos = codeToPos[airportCode];
    for (Edge e : nodes[pos].adj){
        aa.insert(e.airlineCode);
    }
    return (int)aa.size();
}

int Graph::getNrDestinations(std::string &code){
    int pos = codeToPos[code];
    set<string> destinations;
    for (Edge e : nodes[pos].adj){
        destinations.insert(e.destName);
    }
    return (int) destinations.size();
}

int Graph::getNrDestinationsCountries(std::string &code){
    int pos = codeToPos[code];
    set<string> countries;
    for (Edge e : nodes[pos].adj){
        countries.insert(nodes[e.dest].airport.getLocation().getCountry());
    }
    return (int) countries.size();
}

int Graph::getNrTotalFlights(){
    int nr = 0;
    for (Node &node : nodes){
        nr += node.adj.size();
    }
    return nr;
}

int Graph::getFlightsAirline(std::string airlineCode){
    int nr = 0;
    for (Node &node : nodes){
        nr += count_if(node.adj.begin(),node.adj.end(),[&airlineCode] (const Edge e) {return e.airlineCode == airlineCode;});
    }
    return nr;
}


int Graph::getArrivalsAirport(std::string code){
    int pos = codeToPos[code] , arrivals = 0;
    for (Node &node : nodes){
        arrivals += count_if(node.adj.begin(),node.adj.end(),[&pos](Edge e){ return e.dest == pos;});
    }
    return arrivals;
}

set<string> Graph::getAirlinesAirport(std::string airportCode){
    int pos = codeToPos[airportCode];
    set<string> res;
    for (Edge e : nodes[pos].adj){
        res.insert(e.airlineCode);
    }
    vector<string> vec(res.begin(),res.end());
    std::sort(vec.begin(), vec.end());
    set<string> s(vec.begin(),vec.end());
    return s;
}