main: main.o list.o
	g++ -o main *.o -std=c++11

main.o: *.cpp
	g++	-o main.o -c *.cpp -std=c++11

list.o: ../Utilities/List.cpp
	g++ -o list.o -c ../Utilities/List.cpp -std=c++11

clean:
	rm *o
	rm main

