#include "Game.hpp"

Game::Game(bool mode, bool first) {
	status = true;
	turn = first;
	_mode = mode;

	int i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			brd[i][j] = 0;
		}
	}
}

Game::~Game() {
}

std::array<std::array<int,15>,15> Game::getBoard() {
	return brd;
}

bool Game::getStatus() {
	return status;
}

void Game::updateBoard(int line, int column, bool turn) {
	if (turn)
		brd[line][column] = 1;
	else
		brd[line][column] = 2;

	Game::testEndGame(line, column, turn);
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

bool Game::testHorizontal(int line, int column, int player) {
	int x = line - 1;
	int cont = 1;

	while (x >= 0 && brd[x][column] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
	}

	x = line + 1;

	while (x <= 14 && brd[x][column] == player) {
		cont++;
		if (cont == 5)
			return true;
		x++;
	}

	return false;
}

bool Game::testVertical(int line, int column, int player) {
	int y = column - 1;
	int cont = 1;

	while (y >= 0 && brd[line][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		y--;
	}

	y = column + 1;

	while (y <= 14 && brd[line][y] == player) {
			cont++;
			if (cont == 5)
				return true;
			y++;
	}

	return false;
}

bool Game::testDiagonal(int line, int column, int player) {
	int x = line - 1;
	int y = column - 1;
	int cont = 1;

	while (x >= 0 && y >= 0 && brd[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
		y--;
	}

	x = line + 1;
	y = column + 1;

	while (x <= 14 && y <= 14 && brd[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x++;
		y++;
	}

	cont = 1;

	x = line - 1;
	y = column + 1;

	while (x >= 0 && y <= 14 && brd[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
		y++;
	}

	x = line + 1;
	y = column - 1;

	while (x <= 14 && y >= 0 && brd[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x++;
		y--;
	}

	return false;
}

void Game::testEndGame(int line, int column, bool turn) {
	int player = 1;
	if (!turn)
		player = 2;

	status = !Game::testHorizontal(line, column, player);
	if (status)
		status = !Game::testVertical(line, column, player);
	if (status)
		status = !Game::testDiagonal(line, column, player);
}

bool Game::isValidMove(int line, int column) {
	if (line <= 14 && line >= 0 && column <= 14 && column >= 0) {
		if (brd[line][column] == 0) {
			return true;
		}
	}

	return false;
}
