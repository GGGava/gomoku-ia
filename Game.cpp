#include "Game.hpp"

Game::Game(bool mode) {
	status = true;
	turn = true;
	
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

void Game::updateBoard(int x, int y, bool turn) {
	if (turn)
		board[y][x] = 1;
	else
		board[y][x] = 2;
}

bool Game::getTurn() {
	return turn;
}

void Game::changeTurn() {
	turn = !turn;
}