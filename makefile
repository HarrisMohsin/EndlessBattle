#makefile for EndlessBattle project
#wake compatible

all: main.o star.o
	gcc -o EndlessBattle.exe main.o star.o

main.o: main.c
	gcc -c main.c

star.o: star.c
	gcc -c star.c


