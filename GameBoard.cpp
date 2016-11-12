//
//  GameBoard.cpp
//

#include "GameBoard.hpp"

// Build the gameboard
// If the landing square is a chute, set the position to the corresponding lower square
// I.e., player slides down to the lower square
// If the landing square is a ladder, set the position to the corresponding higher square
// Player climbs up to the higher square
// Otherwise, player stays put at the landing square

void GameBoard::buildBoard() {
   // CHECKS EVERY SQUARE TO SEE IF CONTAINS A CHUTE, LADDER OR NEITHER.
   for (int i = 0; i < BOARD_SIZE; i++)
   {
      // MOVES POSITION ACCORDINGLY: CLIMBS UP, SLIDES DOWN, OR STAYS PUT
      CELL[i] = checkChutesLadders[i];
   }
}
