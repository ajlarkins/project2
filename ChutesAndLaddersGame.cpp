//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // CREATE PLAYER: ALEC
   Player Alec;
   Alec.setName("Alec");
   Q.enqueue(Alec);
   
   // CREATE PLAYER: GHOST
   Player Ghost;
   Ghost.setName("Ghost");
   Q.enqueue(Ghost);
}


// DESTRUCTOR: DEQUEUE PLAYERS FROM QUEUE
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   while (!Q.empty())
   {
      Q.dequeue();
   }
}

// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero

// RESET GAME
void ChutesAndLaddersGame::resetGame() {
   // DEQUEUE LIST OF PLAYERS
   while (!Q.empty())
   {
      Q.dequeue();
   }
   
   // REBUILD LIST OF PLAYERS
   Player Alec;
   Alec.setName("Alec");
   Alec.setPosition(0);
   Q.enqueue(Alec);
   
   Player Ghost;
   Ghost.setName("Ghost");
   Ghost.setPosition(0);
   Q.enqueue(Ghost);
}


// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name

// PLAY GAME FUNCTION
void ChutesAndLaddersGame::playGame() {
   winner = "NONE";
   while(winner == "NONE")
   {
      Player T = Q.front();
      int tempValue;
      tempValue = T.rollDieAndMove();
      gameBoard.checkChutesLadders()
      
      if (T.getPosition() == WINNING_POSITION)
      {
         cout << "Congratulations " << T.getName() << ", you won!" << endl;
         winner = T.getName();
      }
   }
}
