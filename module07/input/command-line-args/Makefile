
CC = gcc
CFLAGS = -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=c99 -g

.PHONY: build test clean

build: main

main: main.o
	$(CC) $(CFLAGS) $^ -o $@ 

test:
	./main

clean:
	rm -f *.o *.d a.out main
