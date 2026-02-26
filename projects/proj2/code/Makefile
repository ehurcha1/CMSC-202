CXX = g++
CXXFLAGS = -Wall

proj2: proj2.cpp Exercise.o WorkoutPlan.o WorkoutPlanBuilder.o
	$(CXX) $(CXXFLAGS) proj2.cpp Exercise.o WorkoutPlan.o WorkoutPlanBuilder.o -o proj2

WorkoutPlanBuilder.o: WorkoutPlanBuilder.cpp WorkoutPlanBuilder.h WorkoutPlan.h Exercise.h
	$(CXX) $(CXXFLAGS) -c WorkoutPlanBuilder.cpp

WorkoutPlan.o: WorkoutPlan.cpp WorkoutPlan.h Exercise.h
	$(CXX) $(CXXFLAGS) -c WorkoutPlan.cpp

Exercise.o: Exercise.cpp Exercise.h
	$(CXX) $(CXXFLAGS) -c Exercise.cpp

clean:
	rm *~ *.o

run:
	./proj2

submit:
	cp Exercise.cpp Exercise.h WorkoutPlan.cpp WorkoutPlan.h WorkoutPlanBuilder.cpp WorkoutPlanBuilder.h proj2.cpp ~/cs202proj/proj2

extra:
	cp Exercise.cpp Exercise.h WorkoutPlan.cpp WorkoutPlan.h WorkoutPlanBuilder.cpp WorkoutPlanBuilder.h proj2.cpp ~/cs202proj/proj2/extra_credit
