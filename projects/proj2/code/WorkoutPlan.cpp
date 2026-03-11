// Title: WorkoutPlan.cpp
// Author: Elliot Hurchalla
// Date: 3/7/2026
// Description: This is part of the project in CMSC 202.

#include "WorkoutPlan.h"

// Name - WorkoutPlan()
// Desc - Default Constructor - Creates a weekly workout plan and
//        initializes day names
// Preconditions - None
// Postconditions - Day labels are stored for all 7 days
WorkoutPlan::WorkoutPlan() {
  // Initializes the day names for the array
  m_dayNames[0] = "Monday";
  m_dayNames[1] = "Tuesday";
  m_dayNames[2] = "Wednesday";
  m_dayNames[3] = "Thursday";
  m_dayNames[4] = "Friday";
  m_dayNames[5] = "Saturday";
  m_dayNames[6] = "Sunday";
}

// Name - SetDayExercise(int day, const Exercise &exercise)
// Desc - Assigns an exercise to a given day index in the week
// Preconditions - day must be in range 0 to 6
// Postconditions - Matching day stores the provided exercise
void WorkoutPlan::SetDayExercise(int day, const Exercise &exercise) {
  // Check if the day is valid and then sets the exercise
  if (day >= 0 && day < 7) {
    m_weekPlan[day] = exercise;
  }
}

// Name - GetDayExercise(int day)
// Desc - Returns the exercise from a specific day
// Preconditions - Day must be in range 0 to 6
// Postconditions - Matching day returns the provided exercise
Exercise WorkoutPlan::GetDayExercise(int day) const {
  // Checks if the day is valid and return the exercise
  if (day >= 0 && day < 7) { // I'm just now realizing GetIntInRange would have
                             // been useful here
    return m_weekPlan[day];
  }
  return Exercise();
}

// Name - PrintPlan()
// Desc - Displays the 7-day workout plan to the console
// Preconditions - Plan may contain assigned exercises
// Postconditions - Weekly plan text is output to standard output
void WorkoutPlan::PrintPlan() const {
  // Prints the users workout plan
  cout << "=== Your 7-Day CMSC 202 Workout Plan ===" << endl;
  for (int i = 0; i >= 0 && i < 7; i++) {
    cout << m_dayNames[i] << ": " << m_weekPlan[i].GetName() << " ("
         << m_weekPlan[i].GetMuscle() << ", " << m_weekPlan[i].GetDuration()
         << " min)" << endl;
  }
}
