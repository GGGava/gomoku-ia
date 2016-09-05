#include <utility>
#include "Element.hpp"

class IA {
 public:
	IA();
	~IA();
	std::pair<int,int> makeYourMove(int ** _board);
  int heuristic(Element e);

 private:
  int ** board;

};
