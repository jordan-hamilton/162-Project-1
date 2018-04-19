#include <iostream>
#include <cmath>

#include "Board.hpp"


/***********************************************************************************************
** Description: Initialize data members to create a reasonably sized Board as a 2D array if no
** arguments are provided when a Board object is created. Sets the active state of the tile
** where the Ant where will initially be placed to W (white) since the Board is initialized
** with white tiles.
** Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
***********************************************************************************************/
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


/***********************************************************************************************
** Description: Initialize data members to create a Board as a 2D array of the size provided.
** Sets the active state of the tile where the Ant where will initially be placed to W (white)
** since the Board is initialized with white tiles.
** Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
***********************************************************************************************/
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


/***********************************************************************************************
** Description: Loops through the elements in the 2D array to output the board to the screen.
***********************************************************************************************/
void Board::printBoard() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << gameBoard[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


/***********************************************************************************************
** Description: Sets the rows data member to the value of the integer passed to the function if
** its value is greater than 0. Otherwise, this function defaults to adding 25 rows.
***********************************************************************************************/
void Board::setRows(int rowsToAdd) {
  if (rowsToAdd > 0) {
    rows = rowsToAdd;
  } else {
    rows = 25;
  }
}


/***********************************************************************************************
** Description: Returns the rows data member as an integer when called.
***********************************************************************************************/
int Board::getRows() {
  return rows;
}


/***********************************************************************************************
** Description: Sets the columns data member to the value of the integer passed to the function
** if its value is greater than 0. Otherwise, this function defaults to adding 25 columns.
***********************************************************************************************/
void Board::setColumns(int colsToAdd) {
  if (colsToAdd > 0) {
    columns = colsToAdd;
  } else {
    columns = 25;
  }

}


/***********************************************************************************************
** Description: Returns the columns data member as an integer when called.
***********************************************************************************************/
int Board::getColumns() {
  return columns;
}


/***********************************************************************************************
** Description: Takes a pointer to an Ant object and assigns this pointer to the gameAnt
** data member. The Board tile is set as "*" at the Ant's location at the time the Ant was
** assigned as the gameAnt, so this location must exist on the Board (this should be confirmed
** using input validation before the simulation is run).
***********************************************************************************************/
void Board::addAnt(Ant* newAnt) {

  if (newAnt) {

    gameAnt = newAnt;
    gameBoard[gameAnt->getXCoord()][gameAnt->getYCoord()] = '*';

  }

}


/***********************************************************************************************
** Description: If the pointer is a valid address, print the board.
** Next, loop as long as the Ant object has remaining moves by alternating the state of the
** Board tile where the Ant resides from B (black) to W (white) or vice versa, then moving the
** Ant. If the Ant reaches an edge, continue the simulation on the opposite side of the board
** using modular arithmetic. Then, update the state of the current tile based on the char
** element in the 2D array at the Ant's current location and update the char to visually indicate
** the Ant's location. Finally, display the board to the user with the printBoard method.
***********************************************************************************************/
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


/***********************************************************************************************
** Description: Frees dynamic memory allocated to the 2D array by looping through the 2D array.
** Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
***********************************************************************************************/
Board::~Board() {
  for (int i = 0; i < rows; i++) {
    delete [] gameBoard[i];
  }
  delete [] gameBoard;
}
