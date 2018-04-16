#include <string>
#include <iostream>

#include "Menu.hpp"

Menu::Menu() {
  int selectedItem = 0;
}


void Menu::displayMenu() {
  if(!menu.empty()) {
    for (int i = 0; i < menu.size(); i++) {
      std::cout << i+1 << ") " << menu.at(i) << std::endl;
    }
  }
}


void Menu::addMenuItem(std::string choice) {
    menu.push_back(choice);
}


void Menu::promptUser() {
  int selection;
  bool valid = false;

  do {
    std::cout << "Select an available menu option: ";
    std::cin >> selection;

    if (std::cin) {

      if ((selection > 0) && (selection <= menu.size())) {
        valid = true;
        setSelectedItem(selection);
      } else {
        std::cout << "Available menu options are between 1 and " << menu.size() << "." << std::endl;
      }

    } else {
      std::cout << "Invalid entry." << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }

  } while (!valid);

}


void Menu::setSelectedItem(int input) {
  selectedItem = input;
}


int Menu::getSelectedItem() {
  return selectedItem;
}
