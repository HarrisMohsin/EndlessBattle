#makefile for EndlessBattle project
#wake compatible

all: main.o star.o
	gcc -o EndlessBattle.exe main.o star.o

main.o:
	gcc -c main.c

star.o:
	gcc -c star.c


