main: main.o
		g++ -o main *.o -std=c++11

main.o: *.cpp
		g++	-o main.o -c *.cpp -std=c++11

BinaryTree.o: ../Utilities/BinaryTree.cpp
	g++ -o BinaryTree.o -c ../Utilities/BinaryTree.cpp -std=c++11

clean:
	rm *o
	rm main

