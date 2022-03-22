OBJS 	= date.o
SOURCE 	= date.cpp
HEADER	= date.h
OUT = date.out
CC  = g++
FLAGS 	= -g -c -Wall -std=c++11
LFLAGS  =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

date.o: date.cpp
	$(CC) $(FLAGS) date.cpp

clean:
	rm -f $(OBJS) $(OUT)
