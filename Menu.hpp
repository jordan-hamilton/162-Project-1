#ifndef MENU_HPP
#define MENU_HPP

void displayMenu();
//int promptUser();
int getIntChoice(const std::string &prompt, int minVal, int maxVal);
//bool checkIntInput();
bool checkIntInput(int &inputVal, int minVal, int maxVal);

#endif
