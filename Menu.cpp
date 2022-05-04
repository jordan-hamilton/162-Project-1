#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/***********************************************************************************************
** Description: Prints a list of options that the user can be prompted to select to the screen.
** Used before the getIntChoiceFromPrompt function so input can be retrieved.
***********************************************************************************************/
void displayMenu() {
  cout << "1) Start Langton’s Ant simulation" << endl;
  cout << "2) Quit" << endl;
}


/***********************************************************************************************
** Description: Takes a reference to a string used to indicate a prompt for the user to enter
** data, followed by references to integers that output valid values to hint that the user
** should enter an integer value within the entered values. Input is passed to validateInput and
** validateRange to verify that the input is an integer and falls within a valid range for the
** prompt, then the integer value the user entered is returned if it was valid. Otherwise, the
** prompt is repeated.
***********************************************************************************************/
int getIntChoiceFromPrompt(const string &prompt, const int &minVal, const int &maxVal) {

  string userInput;

  do {
    cout << prompt << endl;
    cout << "Valid input range: [" << minVal << " - " << maxVal << "]: ";
    getline(cin, userInput);
  } while(!validateInput(userInput) || !validateRange(stoi(userInput), minVal, maxVal));

return stoi(userInput);

}


/*********************************************************************
** Description: This function accepts a reference to a string, which
** is then looped through to search for non-digit characters. The
** return value is true is there are only digits in the string passed
** to the function, otherwise, the function returns false.
*********************************************************************/
bool validateInput(const string &inputStr) {
  bool isValid = true;

  if (inputStr.empty()) {
    isValid = false;
  }

  for (int i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}


/***********************************************************************************************
** Description: Takes a reference to an integer value to check, and minimum and maximum values.
** If the input is an integer and in the valid range, the function returns true. Otherwise,
** it returns false.
***********************************************************************************************/
bool validateRange(const int &inputVal, const int &minVal, const int &maxVal) {

  if ((inputVal >= minVal) && (inputVal <= maxVal)) {
    return true;
  } else {
    return false;
  }
}
