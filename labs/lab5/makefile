CXX = g++
CXXFLAGS = -Wall


lab5: FarmersMarket.o lab5.cpp
	$(CXX) $(CXXFLAGS) FarmersMarket.o lab5.cpp -o lab5

FarmersMarket.o: FarmersMarket.cpp FarmersMarket.h
	$(CXX) $(CXXFLAGS) -c FarmersMarket.cpp

run:
	./lab5