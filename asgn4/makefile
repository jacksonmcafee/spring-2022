OBJS	= matrix.o
SOURCE  = matrix.cpp
HEADER  = matrix.h
OUT = matrix.out
CC  = g++
FLAGS 	= -g -c -Wall -std=c++11
LFLAGS	= 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp

clean:
	rm -f $(OBJS) $(OUT)
