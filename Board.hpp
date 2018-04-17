/*********************************************************************
** Description: Specification file for the Board class.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board {

  private:
    Ant* gameAnt;
    char activeState;
    char** gameBoard;
    int rows;
    int columns;

  public:
    Board();
    Board(int rowsToAdd, int colsToAdd);
    void printBoard();
    void setRows(int rowsToAdd);
    int getRows();
    void setColumns(int colsToAdd);
    int getColumns();
    void addAnt(Ant* newAnt);
    void simulate();
    ~Board();


};

#endif
