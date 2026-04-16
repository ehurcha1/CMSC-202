CXX = g++
CXXFLAGS = -Wall

lab10: lab10.cpp Olympic.o Ski.o Snowboard.o
	$(CXX) $(CXXFLAGS) lab10.cpp Olympic.o Ski.o Snowboard.o -o lab10

Olympic.o: Olympic.cpp Olympic.h
	$(CXX) $(CXXFLAGS) -c Olympic.cpp

Ski.o: Ski.cpp Ski.h Olympic.h
	$(CXX) $(CXXFLAGS) -c Ski.cpp

Snowboard.o: Snowboard.cpp Snowboard.h Olympic.h
	$(CXX) $(CXXFLAGS) -c Snowboard.cpp

clean:
	rm -f *.o lab10