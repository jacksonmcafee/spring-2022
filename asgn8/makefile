OBJS	= linklist.o main.o
SOURCE	= linklist.cpp main.cpp
HEADER	= linklist.h
OUT	= asgn8.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

linklist.o: linklist.cpp
	$(CC) $(FLAGS) linklist.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)
