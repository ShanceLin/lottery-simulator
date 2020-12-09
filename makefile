CC      = g++
FLAGS  = -Wall -Wextra -g

all: lottery

lottery: lottery.o 
	$(CC) $(FLAGS) lottery.o -o lottery

lottery.o:	lottery.cpp
	$(CC) $(FLAGS) -c lottery.cpp -o lottery.o

clean:
	rm -f *.o lottery