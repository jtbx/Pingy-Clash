main: main.o utils.o
	gcc -o main main.o utils.o

main.o: main.c
	gcc -o main.o -c main.c

utils.o: utils.c
	gcc -o utils.o -c utils.c
