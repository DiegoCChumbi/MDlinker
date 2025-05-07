all: MDlinker

MDlinker: main.o MDLlib.o
	g++ main.o MDLlib.o -o MDlinker

main.o: main.cpp MDLlib.h
	g++ -std=c++17 -c main.cpp

MDLlib.o: MDLlib.cpp MDLlib.h
	g++ -std=c++17 -c MDLlib.cpp

clean:
	rm -f *.o MDlinker
