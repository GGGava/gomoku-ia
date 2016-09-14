#include <array>
class Game {
	public:
		Game(bool mode);
		~Game();
		std::array<std::array<int,15>,15> getBoard();
		bool getStatus();
		void updateBoard(int line, int column, bool turn);
		bool getTurn();
		bool getMode();
		void changeTurn();
		void testEndGame(int line, int column, bool turn);
		bool testHorizontal(int line, int column, int player);
		bool testVertical(int line, int column, int player);
		bool testDiagonal(int line, int column, int player);
		bool isValidMove(int line, int column);

	private:
		int ** board;
		bool status;
		bool turn;
		bool _mode;

		std::array<std::array<int,15>,15> brd;
};
