#include <utility>

class IA {
	public:
	IA();
	~IA();
	std::pair<int,int> makeYourMove(int ** board);
};