project1: main.o Menu.o Ant.o Board.o
	g++ main.o Menu.o Ant.o Board.o -o project1

main.o: main.cpp
	g++ -c main.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

Ant.o: Ant.cpp
	g++ -c Ant.cpp

Board.o: Board.cpp
	g++ -c Board.cpp

clean:
	rm *.o project1
