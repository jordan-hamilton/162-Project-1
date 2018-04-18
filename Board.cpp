#include <iostream>
#include <cmath>

#include "Board.hpp"

Board::Board() {
  setRows(25);
  setColumns(25);

  gameBoard = new char*[rows];
  activeState = 'W';

  for (int i = 0; i < rows; i++) {
    gameBoard[i] = new char[columns];
  }

  for (int j = 0; j < columns; j++) {
    for (int i = 0; i < rows; i++) {
      gameBoard[i][j] = ' ';
    }
  }

}


Board::Board(int rowsToAdd, int colsToAdd) {
  setRows(rowsToAdd);
  setColumns(colsToAdd);

  gameBoard = new char*[rows];
  activeState = 'W';

  for (int i = 0; i < rows; i++) {
    gameBoard[i] = new char[columns];
  }

  for (int j = 0; j < columns; j++) {
    for (int i = 0; i < rows; i++) {
      gameBoard[i][j] = ' ';
    }
  }

}


void Board::printBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << gameBoard[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


void Board::setRows(int rowsToAdd) {
  if (rowsToAdd > 0) {
    rows = rowsToAdd;
  } else {
    rows = 25;
  }
}


int Board::getRows() {
  return rows;
}


void Board::setColumns(int colsToAdd) {
  if (colsToAdd > 0) {
    columns = colsToAdd;
  } else {
    columns = 25;
  }

}


int Board::getColumns() {
  return columns;
}


void Board::addAnt(Ant* newAnt) {

  if (newAnt) {

    gameAnt = newAnt;
    gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] = '*';

  }

}


void Board::simulate() {

  if (gameAnt) {

    printBoard();

    while (gameAnt->getMoves() > 0) {

      if (activeState == 'W') {
        gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] = '#';
        gameAnt->moveRight();

      } else if (activeState == 'B') {
        gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] = ' ';
        gameAnt->moveLeft();

      }

      if (gameAnt->getXCoord() < 0 || gameAnt->getXCoord() >= rows) {
        gameAnt->setXCoord( std::abs(gameAnt->getXCoord() + rows) % rows );
      }

      if (gameAnt->getYCoord() < 0 || gameAnt->getYCoord() >= columns) {
        gameAnt->setYCoord( std::abs(gameAnt->getYCoord() + columns) % columns );
      }

      if (gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] == ' ') {
        activeState = 'W';

      } else if (gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] == '#') {
        activeState = 'B';

      }

      gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] = '*';

      printBoard();

    }
  }

}


Board::~Board() {
  for (int i = 0; i < rows; i++) {
    delete [] gameBoard[i];
  }
  delete [] gameBoard;
}
