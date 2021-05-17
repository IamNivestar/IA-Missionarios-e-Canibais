main: main.o iterative_deepening.o  tree.o build_tree.o
	gcc -o tp main.o iterative_deepening.o tree.o build_tree.o -Wall
	rm *.o 
	./tp

iterative_deepening.o: iterative_deepening.c 
	gcc -c iterative_deepening.c

tree.o: tree.c
	gcc -c tree.c

build_tree.o: build_tree.c
	gcc -c build_tree.c
	
main.o: main.c
	gcc -c main.c


	