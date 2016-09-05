#include "IA.hpp"
#include <time.h>
#include <stdlib.h>

#define DOUBLEWEIGHT 16
#define TRIPLEWEIGHT 64
#define QUADRUPLEWEIGHT 256
#define ATTACKCONSTANT 1
#define DEFENSECONSTANT 1


IA::IA() {
	srand(time(NULL));
}

IA::~IA() {
//	delete board;
}

std::pair<int,int> IA::makeYourMove(int ** _board) {
	board = _board;

	std::pair <int,int> cord;

	cord.first = rand() % 15;
	cord.second = rand() % 15;

	return cord;
}

int heuristic(Element e) {
	int attackValue = ATTACKCONSTANT * (DOUBLEWEIGHT * e.getN_IADoubles()
									+ TRIPLEWEIGHT * e.getN_IATriples()
									+ QUADRUPLEWEIGHT * e.getN_IAQuadruples());

	int defenseValue = DEFENSECONSTANT * (DOUBLEWEIGHT * e.getN_AdvDoubles()
									 + TRIPLEWEIGHT * e.getN_AdvTriples()
									 + QUADRUPLEWEIGHT * e.getN_AdvQuadruples());

	return attackValue - defenseValue;
}
