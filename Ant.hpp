#ifndef ANT_HPP
#define ANT_HPP


#include "Board.hpp"


class Ant {

  private:
    Board antBoard;
    char orientation;

  public:
    Ant();
    Ant(int startingX, int startingY);
    void setOrientation(char direction);
    char getOrientation();

};

#endif
