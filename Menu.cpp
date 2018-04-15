#include <string>
#include <iostream>

#include "Menu.hpp"

//using std::cin;
using std::cout;
using std::endl;


Menu::Menu() {
  setChoices(0);
}


Menu::Menu(int numberOfChoices) {
  setChoices(numberOfChoices);
}


void Menu::displayMenu() {
  if(!menu.empty()) {
    for int i = 0; i < menu.size(); i++) {
      cout << i+1 << ". " << menu.at(i) << endl;
    }
  }
}


void Menu::addMenuItem(std::string choice) {
  menu.push_back(choice);
}


void Menu::setChoices(int numberOfChoices) {
  choices = numberOfChoices;
}


int Menu::getChoices(){
  return choices;
}
