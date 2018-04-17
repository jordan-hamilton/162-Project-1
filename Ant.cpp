#include "Ant.hpp"


Ant::Ant() {
  setOrientation(N);
  setXCoord(0);
  setYCoord(0);
}


Ant::Ant(int startingX, int startingY) {
  setOrientation(N);
  setXCoord(startingX);
  setYCoord(startingY);
}


void Ant::moveLeft() {

}


void Ant::moveRight() {

}


void Ant::setXCoord(int xIn) {
  xCoord = xIn;
}


int Ant::getXCoord() {
  return xCoord;
}


void Ant::setYCoord(int yIn) {
  yCoord = yIn;
}


int Ant::getYCoord() {
 return yCoord;
}


void Ant::setOrientation(Direction dir) {
  orientation = dir;
}


Direction Ant::getOrientation() {
  return orientation;
}


void Ant::setMoves(int movesInput) {
  if (movesInput <= 0) {
    moves = movesInput;
  }
}


int Ant::getMoves() {
  return moves;
}
