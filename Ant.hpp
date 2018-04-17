#ifndef ANT_HPP
#define ANT_HPP

enum Direction { N, S, E, W };

class Ant {

  private:
    Direction orientation;
    int moves;
    int xCoord;
    int yCoord;

  public:
    Ant();
    Ant(int startingX, int startingY, int startingMoves);
    void moveLeft();
    void moveRight();
    void setXCoord(int xIn);
    int getXCoord();
    void setYCoord(int yIn);
    int getYCoord();
    void setOrientation(Direction dirIn);
    Direction getOrientation();
    void setMoves(int movesIn);
    int getMoves();

};

#endif
