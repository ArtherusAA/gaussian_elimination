.PHONY: all clean

all: program

clean:
	rm -rf program *.o


matrix_io.o: matrix_io.h matrix_io.c
	gcc -c -o matrix_io.o matrix_io.c 
gauss.o: gauss.h gauss.c matrix_io.h
	gcc -c -o gauss.o gauss.c 
main.o: main.c gauss.h matrix_io.h
	gcc -c -o main.o main.c 
program: main.o gauss.o matrix_io.o
	gcc -o program main.o gauss.o matrix_io.o -lm
	rm main.o
	rm gauss.o
	rm matrix_io.o
