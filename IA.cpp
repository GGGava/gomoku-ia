#include "IA.hpp"
#include <time.h>
#include <stdlib.h>

IA::IA() {
	srand(time(NULL));
}

IA::~IA() {

}

std::pair<int,int> IA::makeYourMove(int ** board){
	std::pair <int,int> cord;

	cord.first = rand() % 15;
	cord.second = rand() % 15;

	return cord;
}
