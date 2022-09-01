CFLAGS = -std=c++2a -O3 -g -Wall -Wextra 
LDFLAGS = -lraylib

MazeExplorer: main.cpp
	g++ $(CFLAGS) -o MazeExplorer.out main.cpp $(LDFLAGS)

.PHONY: test clean

test: MazeExplorer
	./MazeExplorer.out

clean:
	rm -r MazeExplorer.out