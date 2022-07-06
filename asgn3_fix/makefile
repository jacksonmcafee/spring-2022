OBJS	= bitvector.o
SOURCE  = bitvector.cpp
HEADER  = bitvector.h
OUT = bitvector.out
CC  = g++
FLAGS 	= -g -c -Wall -std=c++11
LFLAGS	= 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bitvector.o: bitvector.cpp
	$(CC) $(FLAGS) bitvector.cpp

clean:
	rm -f $(OBJS) $(OUT)
