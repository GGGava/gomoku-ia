#include <utility>

class Game {
	public:
		Game(bool mode);
		~Game();
		int ** getBoard();
		bool getStatus();
		void updateBoard(int x, int y, bool turn);
		bool getTurn();
		bool getMode();
		void changeTurn();
		void testEndGame();
		
	private:
		int ** board;
		bool status;
		bool turn;
		bool _mode;
};