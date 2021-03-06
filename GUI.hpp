#include "Game.hpp"
#include "IA.hpp"

class GUI {
 public:
	GUI();
	~GUI();
	void run();
	bool getMode();
	bool getFirst(bool gameMode);
	void buildBoard();
	void move(bool turn);
	std::pair<int,int> getPlayerMovement();

 private:
 	Game * _game;
 	IA* _ia;
};
