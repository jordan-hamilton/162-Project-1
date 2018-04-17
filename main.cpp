#include <iostream>
#include <string>

#include "Menu.hpp"
#include "Board.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int requestedRows, requestedCols, startingRow, startingCol, requestedSteps;

  displayMenu();

  if (getIntChoice("Select an available menu option:", 1 , 2) == 2) {
    return 0;
  } else {
    requestedRows = getIntChoice("How many rows should there be on this board?", 1, std::numeric_limits<int>::max());
    requestedCols = getIntChoice("How many columns should there be on this board?", 1, std::numeric_limits<int>::max());
    startingRow = getIntChoice("Which row should the ant start in?", 0, requestedRows);
    startingCol = getIntChoice("Which column should the ant start in?", 0, requestedCols);
    requestedSteps = getIntChoice("How many steps should there be in this simulation?", 0, std::numeric_limits<int>::max());

    Board antBoard(requestedRows, requestedCols);
    cout << "Rows: " << antBoard.getRows() << endl;
    cout << "Columns: " << antBoard.getColumns() << endl;
    antBoard.printBoard();
  }

  return 0;
}
