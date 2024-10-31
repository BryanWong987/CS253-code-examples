
CC = gcc
CFLAGS = -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=c99 -g

.PHONY: build test clean

build: char-count char-count2 csv

char-count: char-count.o
	$(CC) $(CFLAGS) $^ -o $@

char-count2: char-count2.o
	$(CC) $(CFLAGS) $^ -o $@ 

csv: csv.o
	$(CC) $(CFLAGS) $^ -o $@ 

test:
	./main

clean:
	rm -f *.o *.d a.out main char-count char-count2 csv
