#ifndef Element_HPP
#define Element_HPP

#include <list>
#include <array>

class Element {
 public:
   using Array = std::array<std::array<int,15>,15>;
   Element(const Array& _board, std::pair<int,int> _move, bool _turn, std::array<int,6> counters);
   Element(const Array& _board);
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
   std::array<int,6> getCounters();
   void verifyBlock(std::pair<int,int> cord, bool player);
   void updateCounters(int nBlocks, bool player);
   std::list<std::pair<int,int>> getPossibleMoves();
   std::array<std::array<int,15>,15> getBoard();
   bool isLeaf();

 private:
   Array board;
   std::array<int,6> blockCounters;
   bool leaf = false;
};

#endif
