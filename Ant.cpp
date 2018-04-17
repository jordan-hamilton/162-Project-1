#include "Ant.hpp"


Ant::Ant() {
  setOrientation(N);
  setXCoord(0);
  setYCoord(0);
  setMoves(0);
}


Ant::Ant(int startingX, int startingY, int startingMoves) {
  setOrientation(N);
  setXCoord(startingX);
  setYCoord(startingY);
  setMoves(startingMoves);
}


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
  moves = movesInput;
}


int Ant::getMoves() {
  return moves;
}
