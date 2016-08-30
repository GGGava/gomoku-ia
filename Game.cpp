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
	
	while (x >= 0 && board[x][column] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
	}
	
	x = line + 1;
	
	while (x <= 14 && board[x][column] == player) {
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
	
	while (y >= 0 && board[line][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		y--;
	}
	
	y = column + 1;
	
	while (y <= 14 && board[line][y] == player) {
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
	
	while (x >= 0 && y >= 0 && board[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
		y--;
	}
	
	x = line + 1;
	y = column + 1;
	
	while (x <= 14 && y <= 14 && board[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x++;
		y++;
	}
	
	cont = 1;
	
	x = line - 1;
	y = column + 1;
	
	while (x >= 0 && y <= 14 && board[x][y] == player) {
		cont++;
		if (cont == 5)
			return true;
		x--;
		y++;
	}
	
	x = line + 1;
	y = column - 1;
	
	while (x <= 14 && y >= 0 && board[x][y] == player) {
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
		if (board[line][column] == 0) {
			return true;
		}
	}
	
	return false;
}
