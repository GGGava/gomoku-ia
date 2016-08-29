#include "Game.hpp"

class GUI {
 public:
	GUI();
	~GUI();
	void run();
	bool getMode();
	void buildBoard();
	void printBoard(int ** board);

 private:
 	Game * _game;
};