/*********************************************************************
** Description: Header file for the determinant function.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

void displayMenu();
//int promptUser();
int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal);
//bool checkIntInput();
bool checkIntInput(const int &inputVal, const int &minVal, const int &maxVal);

#endif
