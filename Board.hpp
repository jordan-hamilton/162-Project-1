#ifndef BOARD_HPP
#define BOARD_HPP

class Board {

  private:
    int** gameBoard;
    int rows;
    int columns;

  public:
    Board();
    Board(int rowsToAdd, int colsToAdd);
    void setRows(int rowsToAdd);
    int getRows();
    void setColumns(int colsToAdd);
    int getColumns();
    ~Board();
    
};

#endif
