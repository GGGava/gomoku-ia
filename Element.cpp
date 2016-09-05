#include "Element.hpp"
#include <algorithm>

Element::Element(int ** _board) {
  int i = 0;
  int j = 0;

  board = new int*[15];

  std::copy(&_board[0][0], &_board[0][0]+15*15,&board[0][0]);

  n_IADoubles = 1;
  n_IATriples = 1;
  n_IAQuadruples = 1;

  n_AdvDoubles = 1;
  n_AdvTriples = 1;
  n_AdvQuadruples = 1;
}

Element::~Element() {
  delete board;
}

int Element::searchNVertical(int line, int column, int player) {
	int y = column - 1;
	int cont = 1;

	while (y >= 0 && board[line][y] == player) {
		cont++;
		y--;
	}

	y = column + 1;

	while (y <= 14 && board[line][y] == player) {
			cont++;
			y++;
	}

	return cont;
}

int Element::searchNHorizontal(int line, int column, int player) {
	int x = line - 1;
	int cont = 1;

	while (x >= 0 && board[x][column] == player) {
		cont++;
		x--;
	}

	x = line + 1;

	while (x <= 14 && board[x][column] == player) {
		cont++;
		x++;
	}

	return cont;
}

int Element::searchNDiagonal1(int line, int column, int player) {
	int x = line - 1;
	int y = column - 1;
	int cont = 1;

	while (x >= 0 && y >= 0 && board[x][y] == player) {
		cont++;
		x--;
		y--;
	}

	x = line + 1;
	y = column + 1;

	while (x <= 14 && y <= 14 && board[x][y] == player) {
		cont++;
		x++;
		y++;
	}

	return cont;
}

int Element::searchNDiagonal2(int line, int column, int player) {
	int cont = 1;
	int x = line - 1;
	int y = column + 1;

	while (x >= 0 && y <= 14 && board[x][y] == player) {
		cont++;
		x--;
		y++;
	}

	x = line + 1;
	y = column - 1;

	while (x <= 14 && y >= 0 && board[x][y] == player) {
		cont++;
		x++;
		y--;
	}

	return cont;
}

int Element::getN_IADoubles() {
  return n_IADoubles;
}

int Element::getN_IATriples() {
  return n_IATriples;
}

int Element::getN_IAQuadruples() {
  return n_IAQuadruples;
}

int Element::getN_AdvDoubles() {
  return n_AdvDoubles;
}

int Element::getN_AdvTriples() {
  return n_AdvTriples;
}

int Element::getN_AdvQuadruples() {
  return n_AdvQuadruples;
}
