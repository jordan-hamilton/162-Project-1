#ifndef MENU_HPP
#define MENU_HPP

#include <vector>

class Menu {

  private:
    std::vector<std::string> menu;
    int choices;
    
  public:
    Menu();
    void displayMenu();
    void addMenuItem(std::string choice);
    void setChoices(int numberOfChoices);
    int getChoices();
};

#endif
