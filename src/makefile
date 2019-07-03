all: main.o core.o
	gcc -O3 main.o core.o -o morse
	make clean
	clear

core.o: core.c includes/core.h
	gcc -O3 -c core.c

main.o: main.c
	gcc -O3 -c main.c

clean:
	rm *.o