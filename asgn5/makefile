OBJS	= circle.o main.o rectangle.o shape.o square.o triangle.o
SOURCE	= circle.cpp main.cpp rectangle.cpp shape.cpp square.cpp triangle.cpp
HEADER	= circle.h rectangle.h shape.h square.h triangle.h
OUT	= asgn5.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

circle.o: circle.cpp
	$(CC) $(FLAGS) circle.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

rectangle.o: rectangle.cpp
	$(CC) $(FLAGS) rectangle.cpp -std=c++11

shape.o: shape.cpp
	$(CC) $(FLAGS) shape.cpp -std=c++11

square.o: square.cpp
	$(CC) $(FLAGS) square.cpp -std=c++11

triangle.o: triangle.cpp
	$(CC) $(FLAGS) triangle.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)
