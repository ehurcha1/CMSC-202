//Title: proj2.cpp
//Author: Jeremy Dixon
//Date: 2/17/2026
//Description: Driver program for Project 2 (Workout Plan Builder) in CMSC 202.
//             Loads exercises from a file and launches a menu to let the user
//             build, view, save, or load a 7-day workout plan.

#include <iostream>
#include "WorkoutPlanBuilder.h"
using namespace std;

// Name - main()
// Desc - Entry point for the program. Loads exercises from exercises.txt and
//        automatically starts the Workout Plan menu.
// Preconditions - exercises.txt must exist in the same directory as the executable
// Postconditions - User can interact with the menu until they choose to quit
int main() {
  srand(time(NULL));
  
  // Create a WorkoutPlanBuilder object (starts with 0 loaded exercises)
  WorkoutPlanBuilder builder;

  // Load exercises from the input file
  int exerciseCount = builder.LoadExercises("exercises.txt");

  // If loading fails or returns 0 exercises, end the program
  if (exerciseCount <= 0) {
    cout << "Unable to load exercises from exercises.txt" << endl;
    return 1;
  }

  // Confirm how many exercises were loaded
  cout << "Loaded " << exerciseCount << " exercises from exercises.txt" << endl;

  // Automatically start the menu so the user can build/view/save/load a plan
  builder.RunMenu();

  return 0;
}
