class Game {
	public:
		Game(bool mode);
		~Game();
		int ** getBoard();
		bool getStatus();
		void updateBoard(int x, int y, bool turn);
		bool getTurn();
		void changeTurn();
		
	private:
		int ** board;
		bool status;
		bool turn;
};