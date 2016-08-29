#include <iostream>
#include "GUI.hpp"

	
GUI::GUI() {
	bool mode = GUI::getMode();
	_game = new Game(mode);
}

GUI::~GUI() {

}

void GUI::run() {
	GUI::buildBoard();

	while(Game::getStatus()){
		
	}
}

bool GUI::getMode(){
	bool mode;

	std::cout << "Qual o modo de jogo?\n (0) Single Player \n (1) Multi Player" << std::endl;
	std::cin >> mode;
	std::cout << mode << std::endl;

	return mode;
}

void GUI::buildBoard(){
	int** board = _game->getBoard();

	std::cout << "\n\n Tabuleiro:" << std::endl;

	int i;
	int j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++){
			std::cout << *board[j] << " | ";
		}
		std::cout << std::endl;
	}
}




