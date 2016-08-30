#include <iostream>
#include "GUI.hpp"

GUI::GUI() {
	system("clear");

	_game = new Game(GUI::getMode());
	_ia = new IA();
}

GUI::~GUI() {
 delete _game;
 delete _ia;
}

void GUI::run() {
	GUI::buildBoard();

	while (_game->getStatus()) {
		_game->changeTurn();

		GUI::move(_game->getTurn());

		GUI::buildBoard();
		_game->testEndGame();
	}

	std::cout << "\n--- FIM DE JOGO ---" << std::endl;
	if (_game->getTurn())
		std::cout << "\nJogador 1 ganhou!" << std::endl;
	else
		std::cout << "\nJogador 2 ganhou!" << std::endl;
}

bool GUI::getMode() {
	bool mode;

	std::cout << "Qual o modo de jogo?\n (0) Player vs IA \n (1) Player vs Player" << std::endl;
	std::cin >> mode;

	system("clear");

	if (!mode)
		std::cout << "Escolhido modo Player vs IA" << std::endl;
	else
		std::cout << "Escolhido modo Player vs Player" << std::endl;

	return mode;
}

void GUI::buildBoard() {
	int ** board = _game->getBoard();

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

void GUI::move(bool turn) {
	std::pair <int,int> cord;
	bool validMove = false;

	while (!validMove) {
		if (turn) {
			std::cout << "\nVez do Jogador 1" << std::endl;
			cord = GUI::getPlayerMovement();
		} else {
			if (_game->getMode()) {
				std::cout << "\nVez do Jogador 2" << std::endl;
				cord = GUI::getPlayerMovement();
			}	else {
				std::cout << "\nVez da IA" << std::endl;
				cord = _ia->makeYourMove(_game->getBoard());
			}
		}

		validMove = _game->isValidMove(cord.first, cord.second);

		if (!validMove)
			std::cout << "ERRO: Jogada inválida!" << std::endl;
	}

	system("clear");
	_game->updateBoard(cord.first, cord.second, _game->getTurn());
}



std::pair<int,int> GUI::getPlayerMovement() {
	std::pair <int,int> cord;

	std::cout << "Escolha uma casa do tabuleiro: \nDigite a linha: ";
	std::cin >> cord.first;

	std::cout << "Digite a coluna: ";
	std::cin >> cord.second;

	return cord;
}
