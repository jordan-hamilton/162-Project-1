#include <iostream>
#include <string>

#include "Menu.hpp"
#include "Board.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  Menu antMenu;
  antMenu.addMenuItem("Start Langton’s Ant simulation");
  antMenu.addMenuItem("Quit");
  antMenu.displayMenu();
  antMenu.promptUser();
  if (antMenu.getSelectedItem() == 2) {
    return 0;
  } else {
    //Ant ant;
    Board b1(19, 2);
    cout << "Rows: " << b1.getRows() << endl;
    cout << "Columns: " << b1.getColumns() << endl;
    b1.printBoard();
  }

  return 0;
}
