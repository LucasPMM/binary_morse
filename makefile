all: main.o core.o
	gcc -O3 main.o core.o fila.o -o morse
	make clean
	clear

core.o: src/core.c src/includes/core.h
	gcc -O3 -c src/core.c

fila.o: src/fila.c src/includes/fila.h
	gcc -O3 -c src/fila.c

main.o: src/main.c
	gcc -O3 -c src/main.c

clean:
	rm *.o