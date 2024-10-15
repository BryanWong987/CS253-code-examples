
CC = gcc
CFLAGS = -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=c99 -g
LFLAGS =

PROGS=SimpleTestList UnitTestList RandomTestList
OBJECTS=List.o Node.o Job.o

all: $(PROGS)

SimpleTestList: SimpleTestList.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

UnitTestList: UnitTestList.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

RandomTestList: RandomTestList.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	/bin/rm -f $(PROGS) *.o a.out  *.d

