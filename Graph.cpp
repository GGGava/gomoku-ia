// Grafo implementado por Gustavo Gava para a disciplina de Grafos

#include "Graph.hpp"

Graph::Graph() {

}
Graph::~Graph() {
  
}
void insert(std::string key);
void connect(std::string k1, std::string k2, int weight);
void disconnect(std::string k1, std::string k2);
int size();
std::set<std::string> getElements();
std::set<std::string> getNeighbors(std::string key);
Element getElement(std::string key);
int getDegree(std::string key);
void removeElement(std::string key);
int getConnectionWeight(std::string k1, std::string k2);
