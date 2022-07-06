OBJS	= main.o matrix.o
SOURCE	= main.cpp matrix.cpp
HEADER	= matrix.h
OUT	= matrix.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp 


clean:
	rm -f $(OBJS) $(OUT)

