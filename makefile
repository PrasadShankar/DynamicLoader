CC=g++
CFLAGS=-I.

dynamic-loader: Loader.o
	$(CC) -o dynamic-loader Loader.o -ldl -lpthread

