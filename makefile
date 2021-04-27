.PHONY: all clean

SRC= main.c lib.c

all: program

clean:
		rm -rf *.o 
		rm -rf *.txt
		rm -rf program 

main.o: main.c
		gcc -c -o main.o main.c
lib.o: lib.c
		gcc -c -o lib.o lib.c
program: main.o lib.o
		gcc -o program main.o lib.o