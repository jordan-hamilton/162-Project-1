#include <string>
#include <iostream>
#include <limits>

#include "Menu.hpp"

void displayMenu() {
  std::cout << "1) Start Langton’s Ant simulation" << std::endl;
  std::cout << "2) Quit" << std::endl;
}


int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal) {

  int userInput;

  do {
    std::cout << prompt << std::endl;
    std::cout << "Valid input range: [" << minVal << " - " << maxVal << "]: ";
    std::cin >> userInput;
  } while(!checkIntInput(userInput, minVal, maxVal));

return userInput;

}

bool checkIntInput(const int &inputVal, const int &minVal, const int &maxVal) {

  if (!std::cin) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  } else {

    if ((inputVal >= minVal) && (inputVal <= maxVal)) {
      return true;
    } else {
      return false;
    }
  }
}
