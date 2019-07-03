all: main.o core.o fila.o
	gcc -O3 main.o fila.o core.o -o morse
	make clean
	clear

fila.o: fila.c includes/fila.h
	gcc -O3 -c fila.c

core.o: core.c includes/core.h
	gcc -O3 -c core.c

main.o: main.c
	gcc -O3 -c main.c

clean:
	rm *.o