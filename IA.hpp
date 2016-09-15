#include <iostream>
#include "Element.hpp"

class IA {
	using Array = Element::Array;
 public:
	IA();
	~IA();
	std::pair<int,int> makeYourMove(Array _board);
  int heuristic(Element e);
  int minimax(Element e, int level, bool player, int alpha, int beta);
  std::pair<int,int> minimaxStart(Element e);
  int utility(int level, bool player);

 private:

};
