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

  if (getIntChoiceFromPrompt("Select an available menu option.", 1 , 2) == 2) {
    return 0;
  } else {
    requestedRows = getIntChoiceFromPrompt("How many rows should there be on this board?", 1, std::numeric_limits<int>::max());
    requestedCols = getIntChoiceFromPrompt("How many columns should there be on this board?", 1, std::numeric_limits<int>::max());
    startingRow = getIntChoiceFromPrompt("Which row should the ant start in?\nNote: Row 0 is the top row.", 0, requestedRows-1);
    startingCol = getIntChoiceFromPrompt("Which column should the ant start in?\nNote: Column 0 is the left row.", 0, requestedCols-1);
    requestedSteps = getIntChoiceFromPrompt("How many steps should there be in this simulation?", 1, std::numeric_limits<int>::max());

    Board antBoard(requestedRows, requestedCols);
    Ant gameAnt(startingRow, startingCol, requestedSteps);
    antBoard.addAnt(&gameAnt);
    antBoard.simulate();
  }

  return 0;
}
