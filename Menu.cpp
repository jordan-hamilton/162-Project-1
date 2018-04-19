#include <string>
#include <iostream>
#include <limits>

#include "Menu.hpp"


/***********************************************************************************************
** Description: Prints a list of options that the user can be prompted to select to the screen.
** Used before the getIntChoiceFromPrompt function so input can be retrieved.
***********************************************************************************************/
void displayMenu() {
  std::cout << "1) Start Langton’s Ant simulation" << std::endl;
  std::cout << "2) Quit" << std::endl;
}


/***********************************************************************************************
** Description: Takes a references to a string used to indicate a prompt for the user to enter
** data, followed by references to integers that output valid values to hint that the user
** should enter an integer value within the entered values. Input is passed to checkIntInput
** for basic validation, then the integer value the user entered is returned if it was valid.
** Otherwise, the prompt is repeated.
***********************************************************************************************/
int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal) {

  int userInput;

  do {
    std::cout << prompt << std::endl;
    std::cout << "Valid input range: [" << minVal << " - " << maxVal << "]: ";
    std::cin >> userInput;
  } while(!checkIntInput(userInput, minVal, maxVal));

return userInput;

}


/***********************************************************************************************
** Description: Takes a reference to an integer value to check, and minimum and maximum values.
** If the input is of the incorrect type, this clears the failbit, ignores the rest of the
** input, and returns false. If the input is an integer and in the valid range, the function
** returns true. Otherwise, it returns false.
** Source: http://en.cppreference.com/w/cpp/io/basic_ios/clear
** Source: http://www.cplusplus.com/reference/istream/istream/ignore/
***********************************************************************************************/
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
