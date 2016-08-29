#include "Game.hpp"

class GUI {
 public:
	GUI();
	~GUI();
	void run();
	bool getMode();
	void buildBoard();

 private:
 	Game *_game;
};