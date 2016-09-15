#include "IA.hpp"

#define DOUBLEWEIGHT 16
#define TRIPLEWEIGHT 64
#define QUADRUPLEWEIGHT 256
#define ATTACKCONSTANT 1
#define DEFENSECONSTANT 1
#define MAX 4

IA::IA() {
}

IA::~IA() {
}

std::pair<int,int> IA::makeYourMove(Array _board) {

	Element e(_board);
	std::pair<int,int> cord;
	cord = minimaxStart(e);

	return cord;
}

int IA::heuristic(Element e) {
	int attackValue = ATTACKCONSTANT * (DOUBLEWEIGHT * e.getN_IADoubles()
									+ TRIPLEWEIGHT * e.getN_IATriples()
									+ QUADRUPLEWEIGHT * e.getN_IAQuadruples());

	int defenseValue = DEFENSECONSTANT * (DOUBLEWEIGHT * e.getN_AdvDoubles()
									 + TRIPLEWEIGHT * e.getN_AdvTriples()
									 + QUADRUPLEWEIGHT * e.getN_AdvQuadruples());

	return attackValue;
}

int IA::minimax(Element e, int level, bool player, int alpha, int beta) {
	if (false) {
		return this->utility(level);
	} else if (level == MAX) {
		return this->heuristic(e);
	}

	std::list<std::pair<int,int>> children = e.getPossibleMoves();

	if (!player) {
		for (auto it = children.begin(); it != children.end(); ++it) {
			Element newElement(e.getBoard(),*it, !player, e.getCounters());

			int score = minimax(newElement, level + 1, !player, alpha, beta);

			if (score > alpha) {
				alpha = score;
			}

			if (alpha >= beta) {
				break;
			}
		}

		return alpha;
	}

	else{
		for (auto it = children.begin(); it != children.end(); ++it) {
			Element newElement(e.getBoard(), *it, !player, e.getCounters());

			int score = minimax(newElement, level + 1, !player, alpha, beta);

			if (score < beta) {
				beta = score;
			}

			if (alpha >= beta) {
				break;
			}
		}

		return beta;
	}
}

std::pair<int,int> IA::minimaxStart(Element e){
	std::list<std::pair<int,int>> children = e.getPossibleMoves();
	std::pair<int,int> ret;

	int alpha = -1000000;
	int beta = 1000000;

	for (auto it = children.begin(); it != children.end(); ++it) {
		Element newElement(e.getBoard(),(*it), false, e.getCounters());

		int score = minimax(newElement, 1, false, alpha, beta);

		if (score > alpha) {
			alpha = score;
			ret = *it;
		}

		if (alpha >= beta) {
			break;
		}
	}

	std::cout << "Heuristica : " << alpha << std::endl;
	return ret;
}

int IA::utility(int level) {
	return 32 * QUADRUPLEWEIGHT * (MAX/level);
}
