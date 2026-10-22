
.PHONY: all clean

all: a.out

a.out: main.o add.o sub.o multiplication.o apc.o compare.o
	gcc main.o add.o sub.o multiplication.o apc.o compare.o -o a.out

main.o: main.c apc.h
	gcc -c main.c -o main.o

add.o: addition.c apc.h
	gcc -c addition.c -o add.o

sub.o: subs.c apc.h
	gcc -c subs.c -o sub.o

multiplication.o: multiplication.c apc.h
	gcc -c multiplication.c -o multiplication.o

apc.o: apc.c apc.h
	gcc -c apc.c -o apc.o

compare.o: compare.c apc.h
	gcc -c compare.c -o compare.o


clean:
	rm -f *.o