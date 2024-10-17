
CC = gcc
CFLAGS = -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=c99 -g

.PHONY: build test clean

build: UnitTest

UnitTest: UnitTest.o threed.o
	$(CC) $(CFLAGS) $^ -o $@ 

test:
	./UnitTest

clean:
	rm -f *.o *.d a.out UnitTest
