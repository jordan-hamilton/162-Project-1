#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board {

  private:
    Ant gameAnt;
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
    ~Board();

};

#endif
