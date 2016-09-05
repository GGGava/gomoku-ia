#include "Vertice.hpp"
#include <unordered_map> 
#include <iostream>

class Grafo {
protected :
	std::unordered_map<std::string, Vertice*> graf;
	std::set<std::string> list;
public :
	
	Grafo() {
	}
	void insere(std::string key) {
		std::cout << key << " adicionado" << std::endl;
		Vertice * v1 = new Vertice();
		graf[key] = v1;
	}
	
	void conecta(std::string k1, std::string k2, int peso) {
		if (graf.count(k1) == 1 && graf.count(k2) == 1) {
			std::cout << k1 << " ligado com " << k2 << std::endl;
			this->getVertice(k1)->insere(k2, peso);
			this->getVertice(k2)->insere(k1, peso);
		}
	}

	void desconecta(std::string k1, std::string k2) {
		if (graf.count(k1) == 1 && graf.count(k2) == 1) {
			std::cout << k1 << " desconectado de " << k2 << std::endl;
			this->getVertice(k1)->remove(k2);
			this->getVertice(k2)->remove(k1);
		}
	}

	int ordem() {
		return graf.size();
	}

	std::set<std::string> getVertices() {
		std::set<std::string> con;
		std::unordered_map<std::string, Vertice*>::iterator it;
		for(it = graf.begin(); it != graf.end(); it++){
			con.insert((*it).first);
		}
		return con;
	}

	std::set<std::string> getAdjacentesVertice(std::string key) {
		return getVertice(key)->getAdjacentes();
	}

	Vertice* getVertice(std::string key) {
		if (graf.count(key) == 1)
			return graf[key];
	}

	int getGrau(std::string key){
		if (graf.count(key) == 1)	
			return getVertice(key)->grau();
	}

	void removeVertice(std::string key) {
		Vertice * vert = this->getVertice(key);
		std::set<std::string> adj = vert->getAdjacentes();
		std::unordered_map<std::string, Vertice*>::iterator it;
		for(it = graf.begin(); it != graf.end(); it++){
			this->getVertice((*it).first)->remove(key);
		}	
		graf.erase(key);
	}

	int pesoAresta(std::string k1, std::string k2) {
		return getVertice(k1)->getPesoAresta(k2);
	}

	bool ciclo(std::string init){
		list.erase(list.begin(), list.end());
		return depthSearch(init, init);
	}

	bool depthSearch(std::string key, std::string lastKey) {
		if (list.count(key) == 1){
			return true;
		}
		list.insert(key);
		Vertice* vert = this->getVertice(key);
		std::set<std::string> adja = vert->getAdjacentes();
		std::set<std::string>::iterator it;
		for(it = adja.begin(); it != adja.end(); it++){
			if((*it) != lastKey) {
				if (depthSearch((*it), key))
					return true;
			}
		}
	return false;
	}
};