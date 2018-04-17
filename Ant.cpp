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
      setYCoord(yCoord - 1);
      setOrientation(W);
      break;
    }
    case S:
    {
      setYCoord(yCoord + 1);
      setOrientation(E);
      break;
    }
    case E:
    {
      setXCoord(xCoord - 1);
      setOrientation(N);
      break;
    }
    case W:
    {
      setXCoord(xCoord + 1);
      setOrientation(S);
      break;
    }
  }

  setMoves(moves - 1);
}


void Ant::moveRight() {
  switch (getOrientation()) {

    case N:
    {
      setYCoord(yCoord - 1);
      setOrientation(E);
      break;
    }
    case S:
    {
      setYCoord(yCoord + 1);
      setOrientation(W);
      break;
    }
    case E:
    {
      setXCoord(xCoord - 1);
      setOrientation(S);
      break;
    }
    case W:
    {
      setXCoord(xCoord + 1);
      setOrientation(N);
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
