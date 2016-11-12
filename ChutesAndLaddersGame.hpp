//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

// 1 PERSON IN GROUP, BUT SET TO 2 BECAUSE IT IS THE MINIMUM
const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:
 
   // constructor with the default value of 2 minimim players
   ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);
   
   // destructor
   ~ChutesAndLaddersGame();
   
   // accessors
   // RETURNS MINIMUM NUMBER OF PLAYERS
   long getNumberOfPlayers() {

      return MIN_NUMBER_OF_PLAYERS;
   }
   
   // RETURNS THE WINNER
   string getWinner() { 
      return winner; 
   }

   // RESETS THE GAME
   void resetGame();

   // PLAYS THE GAME
   void playGame();
private:
   const int WINNING_POSITION = 100;
   
   string winner;       // the winner
   GameBoard gameBoard; // the game board

   // ARRAYQUEUE
   ArrayQueue<Player> Q;
};
