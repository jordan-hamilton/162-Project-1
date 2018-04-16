#ifndef MENU_HPP
#define MENU_HPP

#include <vector>

class Menu {

  private:
    std::vector<std::string> menu;
    int selectedItem;

  public:
    Menu();
    void displayMenu();
    void addMenuItem(std::string choice);
    void promptUser();
    void setSelectedItem(int input);
    int getSelectedItem();
};

#endif
