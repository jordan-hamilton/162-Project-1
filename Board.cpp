#include "Board.hpp"

Board::Board() {
  setRows(5);
  setColumns(5);
  gameBoard = new int*[rows];

  for (int i = 0; i < rows; i++) {
    gameBoard[i] = new int[columns];
  }
}


Board::Board(int rowsToAdd, int colsToAdd) {
  setRows(rowsToAdd);
  setColumns(colsToAdd);
  gameBoard = new int*[rows];

  for (int i = 0; i < rows; i++) {
    gameBoard[i] = new int[columns];
  }
}


void Board::printBoard() {

}


void Board::setRows(int rowsToAdd) {
  rows = rowsToAdd;
}


int Board::getRows() {
  return rows;
}


void Board::setColumns(int colsToAdd) {
  columns = colsToAdd;
}


int Board::getColumns() {
  return columns;
}


Board::~Board() {
  for (int i = 0; i < rows; i++) {
    delete [] gameBoard[i];
  }
  delete [] gameBoard;
}
