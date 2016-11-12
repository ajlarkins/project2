//
//  Player.cpp
//

#include "Player.hpp"

// ASSIGNMENT OPERATOR
Player& Player::operator=(const Player& p) {
   // USING SET FUNCTIONS
   setName(p.playerName);
   setPosition(p.position);
   die = p.die;
   return *this;
}

// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value

int Player::rollDieAndMove() {
   // ROLL THE DICE
   die.roll();
   // ADD ROLL FROM DICE TO CURRENT POSITION TO GET NEW POSITION AFTER MOVE
   int newPos = getPosition() + die.getFaceValue();
   // CHECK POSITION
   if (newPos < 0)
   {
      // THROW ERROR IF POSITION IS NOT ON BOARD
      throw range_error("OUT OF BOUNDS");
   }
   else if (newPos >= 100)
   {
      // NO CHANGES TO POSITION
      return getPosition();
   }
   else if (newPos >= 0 && newPos < 100)
   {
      // RETURN NEW POSITION AFTER ROLL
      setPosition(getPosition() + die.getFaceValue());
      return getPosition();
   }
   
}
