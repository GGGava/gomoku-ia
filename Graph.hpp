// Grafo implementado por Leandro Perin de Oliveira para a disciplina de Grafos

#include <iostream>
#include <list>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include "Element.hpp"

class Graph {
 public:
  Graph(Element* _element);
  virtual ~Graph();
  void insert(Element* _element);
  void remove(Element* _element);
  void connect(Element* _element1, Element* _element2, int _weight);
  void disconnect(Element* _element1, Element* _element2);
  int order();
  std::list<Element*>* getElements();
  Element* getRandomElement();
  std::list<Element*>* getNeighbors(Element* _element);
  int degree(Element* _element);
  void removeConnections(Element* _element);
 private:
   struct Connection {
     Element* element1;
     Element* element2;
   };
   std::list<Element*>* elementsList;
   std::unordered_map<Connection*, int> connectionsMap;
};