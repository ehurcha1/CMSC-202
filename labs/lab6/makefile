CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp Sandwich.o
        $(CXX) $(CXXFLAGS) lab6.cpp Sandwich.o -o lab6

Sandwich.o: Sandwich.cpp Sandwich.h
        $(CXX) $(CXXFLAGS) -c Sandwich.cpp

run:
        ./lab6

clean:
        rm *~ *.o
