class Element {
 public:
   Element(int ** _board);
   ~Element();
   int searchNVertical(int line, int column, int player);
   int searchNHorizontal(int line, int column, int player);
   int searchNDiagonal1(int line, int column, int player);
   int searchNDiagonal2(int line, int column, int player);
   int getN_IADoubles();
   int getN_IATriples();
   int getN_IAQuadruples();
   int getN_AdvDoubles();
   int getN_AdvTriples();
   int getN_AdvQuadruples();
 private:
   int ** board;
   int n_IADoubles;
   int n_IATriples;
   int n_IAQuadruples;
   int n_AdvDoubles;
   int n_AdvTriples;
   int n_AdvQuadruples;
};
