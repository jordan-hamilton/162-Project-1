project1: main.o Menu.o Ant.o Board.o
	g++ main.o Menu.o Ant.o Board.o -o project1

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++0x -c Ant.cpp

Board.o: Board.cpp Board.hpp Ant.cpp Ant.hpp
	g++ -std=c++0x -c Board.cpp

clean:
	rm *.o project1
