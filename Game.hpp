class Game {
	public:
		Game(bool mode);
		~Game();
		int** getBoard();
	private:
		int** board;
};