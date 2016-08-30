#include "Game.hpp"

Game::Game(bool mode) {
	status = true;
	turn = false;
	_mode = mode;

	board = new int*[15];
	int i, j;
	for (i = 0; i < 15; i++) {
		board[i] = new int[15];
		for (j = 0; j < 15; j++) {
			board[i][j] = 0;
		}
	}
}

Game::~Game() {
	delete board;
}

int ** Game::getBoard() {
	return board;
}

bool Game::getStatus() {
	return status;
}

void Game::updateBoard(int line, int column, bool turn) {
	if (turn)
		board[line][column] = 1;
	else
		board[line][column] = 2;
}

bool Game::getTurn() {
	return turn;
}

void Game::changeTurn() {
	turn = !turn;
}

bool Game::getMode() {
	return _mode;
}

void Game::testEndGame() {
	int i, j;

	int comp = 1;
	if (!turn) {
		comp = 2;
	}

	int contX = 0;
	int contY = 0;

	for (i = 0; i < 15 && status; i++){
		for (j = 0; j < 15; j++){
			if (board[i][j] == comp) {
				contX++;
			} else {
				contX = 0;
			}

			if (board[j][i] == comp) {
				contY++;
			} else {
				contY = 0;
			}

			if (contX == 5 || contY == 5){
				status = false;
				return;
			}
		}
	}


}
