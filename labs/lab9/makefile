CXX = g++
CXXFLAGS = -Wall

lab9: Vehicle.o Car.o Truck.o lab9.cpp
	$(CXX) $(CXXFLAGS) Vehicle.o Car.o Truck.o lab9.cpp -o lab9

Vehicle.o: Vehicle.h Vehicle.cpp
	$(CXX) $(CXXFLAGS) -c Vehicle.cpp

Car.o: Car.h Car.cpp Vehicle.o
	$(CXX) $(CXXFLAGS) -c Car.cpp

Truck.o: Truck.h Truck.cpp Vehicle.o
	$(CXX) $(CXXFLAGS) -c Truck.cpp

run:
	./lab9

clean:
	rm *~
	rm *.o
