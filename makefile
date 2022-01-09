.PHONY: all clean
CC = gcc
AR = ar
FLAGS= -Wall -Werror -g
all: graph 
graph: main.o 
	$(CC) $(FLAGS) -o graph main.o 
main.o: main.c 
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.a graph