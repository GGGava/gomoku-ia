// Grafo implementado por Leandro Perin de Oliveira para a disciplina de Grafos

#include "Graph.hpp"

Graph::Graph(Element* _element) {
  elementsList = new std::list<Element*>;
  elementsList->push_front(_element);
}

Graph::~Graph() {
  delete elementsList;
}

void Graph::insert(Element* _element) {
  elementsList->push_back(_element);
}

void Graph::remove(Element* _element) {
  if (elementsList->size() > 1) {
    this->removeConnections(_element);
    elementsList->remove(_element);
  }
}

void Graph::connect(Element* _element1, Element* _element2, int _weight) {
  Connection* connection = new Connection();
  
  connection->element1 = _element2;
  connection->element2 = _element1;
  connectionsMap.erase(connection);
  
  connection->element1 = _element1;
  connection->element2 = _element2;
  connectionsMap.erase(connection);
  
  connectionsMap.emplace(connection, _weight);  
}

void Graph::disconnect(Element* _element1, Element* _element2) {
  auto it = connectionsMap.begin();
  for (it; it != connectionsMap.end(); ++it) {
    if ((it->first->element1 == _element1 && it->first->element2 == _element2) 
    || (it->first->element1 == _element2 && it->first->element2 == _element1)) {
      Connection* connection = it->first;
      connectionsMap.erase(connection);
      delete connection;
      break;
    }
  }
}

int Graph::order() {
  return elementsList->size();
}

std::list<Element*>* Graph::getElements() {
  return elementsList;
}

Element* Graph::getRandomElement() {
  srand(time(NULL));
  int position = rand() % this->order();
  
  std::list<Element*>::iterator it = elementsList->begin();
  int counter = 0;
  
  while (position > counter) {
    ++it;
    counter++;
  }
  
  return *it;
}

std::list<Element*>* Graph::getNeighbors(Element* _element) {
  std::list<Element*>* neighbors = new std::list<Element*>;
  
  auto it = connectionsMap.begin();
  for (it; it != connectionsMap.end(); ++it) {
    if (it->first->element1 == _element) {
      neighbors->push_back(it->first->element2);
    }
    if (it->first->element2 == _element) {
      neighbors->push_back(it->first->element1);
    }
  }
  
  return neighbors;
}

int Graph::degree(Element* _element) {
  return this->getNeighbors(_element)->size();
}

void Graph::removeConnections(Element* _element) {
  std::list<Element*>* neighbors = this->getNeighbors(_element);
  std::list<Element*>::iterator it = neighbors->begin();
  
  for (it; it != neighbors->end(); it++) {
    this->disconnect(_element, (*it));
  }
}
