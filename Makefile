all: MDlinker

MDlinker: main.o MDlib.o
	g++ main.o MDlib.o -o MDlinker

main.o: main.cpp MDlib.h
	g++ -std=c++17 -c main.cpp

MDLlib.o: MDlib.cpp MDlib.h
	g++ -std=c++17 -c MDLlib.cpp

clean:
	rm -f *.o MDlinker
