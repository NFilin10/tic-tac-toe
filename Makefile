CC = g++
CFLAGS = -std=c++11 -Wall
OBJS = Board.o main.o

TARGET = tictactoe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

Board.o: Board.cpp Board.h
	$(CC) $(CFLAGS) -c Board.cpp

main.o: main.cpp Board.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)
