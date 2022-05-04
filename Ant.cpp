#include "Ant.hpp"


/***********************************************************************************************
** Description: Initialize data members if no arguments are provided when an Ant object is
** created.
***********************************************************************************************/
Ant::Ant() {
  setOrientation(N);
  setXCoord(0);
  setYCoord(0);
  setMoves(0);
}


/***********************************************************************************************
** Description: Initialize data members if arguments for a starting location and number of moves
** are provided when an Ant object is created.
***********************************************************************************************/
Ant::Ant(int startingX, int startingY, int startingMoves) {
  setOrientation(N);
  setXCoord(startingX);
  setYCoord(startingY);
  setMoves(startingMoves);
}


/***********************************************************************************************
** Description: Sets the orientation to left based on the current orientation of the Ant.
** Then, either the current row or column is updated based on what would be considered a forward
** movement from the updated orientation. Then, the number of moves is decremented by 1.
***********************************************************************************************/
void Ant::moveLeft() {

  switch (getOrientation()) {

    case N:
    {
      setOrientation(W);
      setYCoord(yCoord - 1);

      break;
    }
    case S:
    {
      setOrientation(E);
      setYCoord(yCoord + 1);

      break;
    }
    case E:
    {
      setOrientation(N);
      setXCoord(xCoord - 1);
      break;
    }
    case W:
    {
      setOrientation(S);
      setXCoord(xCoord + 1);
      break;
    }
  }

  setMoves(moves - 1);

}


/***********************************************************************************************
** Description: Sets the orientation to right based on the current orientation of the Ant.
** Then, either the current row or column is updated based on what would be considered a forward
** movement from the updated orientation. Then, the number of moves is decremented by 1.
***********************************************************************************************/
void Ant::moveRight() {

  switch (getOrientation()) {

    case N:
    {
      setOrientation(E);
      setYCoord(yCoord + 1);

      break;
    }
    case S:
    {
      setOrientation(W);
      setYCoord(yCoord - 1);
      break;
    }
    case E:
    {
      setOrientation(S);
      setXCoord(xCoord + 1);
      break;
    }
    case W:
    {
      setOrientation(N);
      setXCoord(xCoord - 1);
      break;
    }

  }

  setMoves(moves - 1);

}


/***********************************************************************************************
** Description: Takes an integer value and sets the xCoord data member to this value to indicate
** the Ant's current row.
***********************************************************************************************/
void Ant::setXCoord(int xIn) {
  xCoord = xIn;
}


/***********************************************************************************************
** Description: Returns the xCoord data member as an integer when called.
***********************************************************************************************/
int Ant::getXCoord() {
  return xCoord;
}


/***********************************************************************************************
** Description: Takes an integer value and sets the yCoord data member to this value to indicate
** the Ant's current column.
***********************************************************************************************/
void Ant::setYCoord(int yIn) {
  yCoord = yIn;
}


/***********************************************************************************************
** Description: Returns the yCoord data member as an integer when called.
***********************************************************************************************/
int Ant::getYCoord() {
 return yCoord;
}


/***********************************************************************************************
** Description: Takes an enum data type representing the direction the Ant is facing and sets
** the orientation data member to this value.
***********************************************************************************************/
void Ant::setOrientation(Direction dir) {
  orientation = dir;
}


/***********************************************************************************************
** Description: Returns the orientation data member as a Direction enum data type when called.
***********************************************************************************************/
Direction Ant::getOrientation() {
  return orientation;
}


/***********************************************************************************************
** Description: Takes an integer value representing the number of moves the Ant can make and
** sets the moves data member to this value.
***********************************************************************************************/
void Ant::setMoves(int movesInput) {
  moves = movesInput;
}


/***********************************************************************************************
** Description: Returns the moves data member as an integer when called.
***********************************************************************************************/
int Ant::getMoves() {
  return moves;
}
