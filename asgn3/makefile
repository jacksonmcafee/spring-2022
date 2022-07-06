OBJS	= bitvector.o main.o
SOURCE	= bitvector.cpp main.cpp
HEADER	= bitvector.h
OUT	= bitvector.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bitvector.o: bitvector.cpp
	$(CC) $(FLAGS) bitvector.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)

