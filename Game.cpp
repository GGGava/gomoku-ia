#include "Game.hpp"

Game::Game(bool mode){
	board = new int*[15];
	int i;
	int j;
	for (i = 0; i < 15; i++){
		board[i] = new int[15];
		for (j = 0; j < 15; j++){
			board[i][j] = 0;
		}
	}
}

Game::~Game(){

}

int** Game::getBoard(){
	return board;
}