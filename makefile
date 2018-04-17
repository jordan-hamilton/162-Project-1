project1: main.o Menu.o Ant.o Board.o
	g++ main.o Menu.o Ant.o Board.o -o project1

main.o: main.cpp
	g++ -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

clean:
	rm *.o project1
