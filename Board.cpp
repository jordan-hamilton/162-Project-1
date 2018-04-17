#include <iostream>

#include "Board.hpp"

Board::Board() {
  setRows(25);
  setColumns(25);

  gameBoard = new char*[rows];

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
    gameBoard[newAnt->getXCoord()][newAnt->getYCoord()] = '*';
  }
}


Board::~Board() {
  for (int i = 0; i < rows; i++) {
    delete [] gameBoard[i];
  }
  delete [] gameBoard;
}
