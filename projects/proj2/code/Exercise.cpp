// Title: Exercise.cpp
// Author: Elliot Hurchalla
// Date: 3/7/2026
// Description: This is part of the project in CMSC 202.

#include "Exercise.h"

// Name - Exercise()
// Desc - Default Constructor - Creates an empty exercise with default values
// Preconditions - None
// Postconditions - Exercise object is initialized with blank/zero data
Exercise::Exercise() {
  // Initializes variables to default values
  m_name = "";
  m_muscle = "";
  m_duration = 0;
}

// Name - Exercise(string name, string muscle, int duration)
// Desc - Overloaded Constructor - Creates an exercise with provided name,
//        muscle group, and duration in minutes
// Preconditions - Caller provides exercise data values
// Postconditions - Exercise object is initialized with provided data
Exercise::Exercise(string name, string muscle, int duration) {
  // Initializes variables with provided values
  m_name = name;
  m_muscle = muscle;
  m_duration = duration;
}

// Name - GetName()
// Desc - Returns the exercise name
// Preconditions - Exercise object exists
// Postconditions - Exercise name is returned to caller
string Exercise::GetName() const {
  // Returns the name of the exercise
  return m_name;
}

// Name - GetMuscle()
// Desc - Returns the target muscle group
// Preconditions - Exercise object exists
// Postconditions - Muscle group is returned to caller
string Exercise::GetMuscle() const {
  // Returns the muscle group of the exercise
  return m_muscle;
}

// Name - GetDuration()
// Desc - Returns the exercise duration in minutes
// Preconditions - Exercise object exists
// Postconditions - Duration value is returned to caller
int Exercise::GetDuration() const {
  // Returns the duration of the exercise in minutes
  return m_duration;
}