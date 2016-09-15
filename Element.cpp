#include "Element.hpp"

Element::Element(const Array& _board, std::pair<int,int> _move, bool _turn, std::array<int,6> counters) {
  board = _board;
  blockCounters = counters;
  verifyBlock(_move, _turn);

  if (_turn)
    board[_move.first][_move.second] = 1;
  else
    board[_move.first][_move.second] = 2;
}

Element::Element(const Array& _board) {
  board = _board;

  blockCounters[0] = 0;
  blockCounters[1] = 0;
  blockCounters[2] = 0;

  blockCounters[3] = 0;
  blockCounters[4] = 0;
  blockCounters[5] = 0;
}

Element::~Element() {
}

std::array<std::array<int,15>,15> Element::getBoard() {
  return board;
}


std::list<std::pair<int,int>> Element::getPossibleMoves() {
  std::list<std::pair<int,int>> possibleMoves;

  int i = 0;
  for (i; i < 15; i++) {
    int j = 0;
    for (j; j < 15; j++) {
      if (board[i][j] == 0) {
        std::pair<int,int> _possibleMove = std::make_pair(i,j);

        if (i > 4 && i < 11 && j > 4 && j < 11)
          possibleMoves.push_front(_possibleMove);
        else
          possibleMoves.push_back(_possibleMove);
      }
    }
  }

  return possibleMoves;
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
  return blockCounters[0];
}

int Element::getN_IATriples() {
  return blockCounters[1];
}

int Element::getN_IAQuadruples() {
  return blockCounters[2];
}

int Element::getN_AdvDoubles() {
  return blockCounters[3];
}

int Element::getN_AdvTriples() {
  return blockCounters[4];
}

int Element::getN_AdvQuadruples() {
  return blockCounters[5];
}

void Element::verifyBlock(std::pair<int,int> cord, bool player){
	int playerN = (player) ? 1 : 2;

	updateCounters(searchNVertical(cord.first, cord.second, playerN), player);
	updateCounters(searchNHorizontal(cord.first, cord.second, playerN), player);
	updateCounters(searchNDiagonal1(cord.first, cord.second, playerN), player);
	updateCounters(searchNDiagonal2(cord.first, cord.second, playerN), player);
}

void Element::updateCounters(int nBlocks, bool player) {
	int doubles, triples,quadruples;

	if (!player) {
		doubles = 0;
		triples = 1;
		quadruples = 2;
	} else {
		doubles = 3;
		triples = 4;
		quadruples = 5;
	}

	if (nBlocks == 2) {
		blockCounters[doubles] += 1;
	} else if (nBlocks == 3) {
		blockCounters[triples] += 1;
		blockCounters[doubles] -= 1;
	} else if (nBlocks == 4) {
		blockCounters[quadruples] += 1;
		 blockCounters[triples] -= 1;
	} else if (nBlocks == 5) {
		leaf = true;
	}
}

std::array<int,6> Element::getCounters() {
	return blockCounters;
}

bool Element::isLeaf() {
	return leaf;
}
