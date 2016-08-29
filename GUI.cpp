#include <iostream>
#include "GUI.hpp"
#include <time.h>

GUI::GUI() {
	_game = new Game(GUI::getMode());
}

GUI::~GUI() {
 delete _game;
}

void GUI::run() {
	GUI::buildBoard();
	srand(time(NULL));
	int c = 0;
	//while (_game->getStatus()) {
	while (c < 1500) {
		int x, y;
		
		if (_game->getTurn()) {
			std::cout << "\nVez do Jogador 1" << std::endl;
		} else {
			std::cout << "\nVez do Jogador 2" << std::endl;
		}
		
		// std::cout << "Escolha uma casa do tabuleiro: \nDigite a coordenada X: ";
		// std::cin >> x;
		// std::cout << "Digite a coordenada Y: ";
		// std::cin >> y;
		x = rand() % 15;
		y = rand() % 15;
		
		system("clear");
		
		_game->updateBoard(x, y, _game->getTurn());
		GUI::printBoard(_game->getBoard());
		
		_game->changeTurn();
		
		c++;
	}
}

bool GUI::getMode() {
	bool mode;

	std::cout << "Qual o modo de jogo?\n (0) Single Player \n (1) Multi Player" << std::endl;
	std::cin >> mode;
	
	system("reset");
	
	if (mode == 0)
		std::cout << "Escolhido modo Humano vs IA" << std::endl;
	else
		std::cout << "Escolhido modo Humano vs Humano" << std::endl;

	return mode;
}

void GUI::buildBoard() {
	int ** board = _game->getBoard();
	
	printBoard(board);
}

void GUI::printBoard(int ** _board) {
	int ** board = _board;
	int i,j;

	std::cout << "\n\n Tabuleiro:" << std::endl;
	
	std::cout << "       ";	
	for (i = 0; i < 15; i++) {
		if (i < 10)
			std::cout << "0";
		std::cout << i << "   ";
	}
	std::cout << std::endl;
	
	std::cout << "     ___________________________________________________________________________\n" << std::endl;

	for (i = 0; i < 15; i++) {
		if (i < 10)
			std::cout << "0";
		std::cout << i << "  | ";
		
		std::cout << " ";
		for (j = 0; j < 15; j++){
			switch (board[i][j]) {
				case 0:
					std::cout << "[]   ";
					break;
				case 1:
					std::cout << "\033[1;31mP1   \033[0m";
					break;
				case 2:
					std::cout << "\033[1;34mP2   \033[0m";
					break;
			}
		}
		std::cout << std::endl << "    |" << std::endl;
	}
}