#include <set>
#include <unordered_map>
#include <iostream>

class Vertice {
protected :
	std::unordered_map<std::string, int> adjacentes;

public :
	Vertice() {}
	
	void insere (std::string vert, int peso) {
		adjacentes[vert] = peso;
	}

	void remove (std::string vert) {
		adjacentes.erase(vert);
	}

	std::set<std::string>getAdjacentes() {
		std::set<std::string> adj;
		std::unordered_map<std::string, int>::iterator it;
		for(it = adjacentes.begin(); it != adjacentes.end(); it++){
			adj.insert((*it).first);
		}	
		return adj;
	}

	int grau() {
		return adjacentes.size();
	}

	int getPesoAresta(std::string key) {
		return adjacentes[key];
	}
};