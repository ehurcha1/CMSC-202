// Title: WorkoutPlanBuilder.h
// Author: Jeremy Dixon
// Date: 2/17/2026
// Description: This is part of the project in CMSC 202.

#include "WorkoutPlanBuilder.h"

// Name - WorkoutPlanBuilder()
// Desc - Default Constructor - Creates a builder with zero loaded exercises
// Preconditions - None
// Postconditions - Internal exercise count is set to 0
WorkoutPlanBuilder::WorkoutPlanBuilder() { m_exerciseCount = 0; }

// Name - LoadExercises(const string &filename)
// Desc - Reads exercise records from a file into a fixed array
// Preconditions - filename refers to a readable input file
// Postconditions - m_exerciseCount reflects successfully loaded exercises
int WorkoutPlanBuilder::LoadExercises(const string &filename) {
  ifstream fileWorkouts(filename);

  for (int i = 0; i)
}