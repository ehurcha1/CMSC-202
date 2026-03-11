// Title: WorkoutPlanBuilder.h
// Author: Elliot Hurchalla
// Date: 3/7/2026
// Description: This is part of the project in CMSC 202.

#include "WorkoutPlanBuilder.h"
#include "WorkoutPlan.h"
#include <fstream>
#include <string>
using namespace std;

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

  string name = "";
  while (getline(fileWorkouts, name, ',')) {
    string muscle = "";
    int duration = 0;

    getline(fileWorkouts, muscle, ',');
    fileWorkouts >> duration;
    fileWorkouts.ignore();

    m_exercises[m_exerciseCount] = Exercise(name, muscle, duration);

    m_exerciseCount++;
  }
  return m_exerciseCount;
}

// Name - BuildWeeklyPlan()
// Desc - Builds and returns a 7-day plan from loaded exercises
// Preconditions - At least one exercise has been loaded
// Postconditions - Returned WorkoutPlan contains assignments for each day
WorkoutPlan WorkoutPlanBuilder::BuildWeeklyPlan() const {
  WorkoutPlan plan;

  plan.SetDayExercise(0, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(1, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(2, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(3, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(4, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(5, m_exercises[rand() % m_exerciseCount]);
  plan.SetDayExercise(6, m_exercises[rand() % m_exerciseCount]);

  return plan;
}

// Name - DisplayLoadedExercises() const
// Desc - Prints a numbered list of loaded exercises
// Preconditions - None
// Postconditions - Exercises displayed to cout
void WorkoutPlanBuilder::DisplayLoadedExercises() const {
  cout << "Loaded Exercises:" << endl;
  for (int i = 0; i < m_exerciseCount; i++) {
    cout << setw(2) << i + 1 << ") " << m_exercises[i].GetName() << " - "
         << m_exercises[i].GetMuscle() << " - " << m_exercises[i].GetDuration()
         << " min" << endl;
  }
}

// Name - GetIntInRange(int min, int max) const
// Desc - Gets an int from user in a certain range, re-prompts on invalid input
// Preconditions - min <= max
// Postconditions - Returns validated integer
int WorkoutPlanBuilder::GetIntInRange(int min, int max) const {
  int num = 0;

  cout << "Choose an option (" << min << "-" << max << "): ";
  cin >> num;

  while (num < min || num > max) {
    cout << "Please enter a number between " << min << " and " << max << ": ";
    cin >> num;
  }
  return num;
}

// Name - BuildWeeklyPlanInteractive()
// Desc - Lets the user choose an exercise for each of 7 days
// Preconditions - At least one exercise has been loaded
// Postconditions - Returns a 7-day WorkoutPlan based on user selections
WorkoutPlan WorkoutPlanBuilder::BuildWeeklyPlanInteractive() const {
  WorkoutPlan plan;
  cout << "--- Build a 7-Day Workout Plan ---" << endl;
  DisplayLoadedExercises();
  cout << "Choose an exercise number for each day." << endl;
  for (int i = 0; i < DAYS_IN_WEEK; i++) {
    cout << "Day " << i + 1 << " (1-" << m_exerciseCount << "): ";
    int choice = GetIntInRange(1, m_exerciseCount);
    plan.SetDayExercise(i, m_exercises[choice - 1]);
  }
  cout << "Custom plan created." << endl;
  return plan;
}

// Name - RunMenu()
// Desc - Displays a simple menu so the user can build, view, save, or load a
//        7-day workout plan
// Preconditions - Exercises should be loaded first (LoadExercises)
// Postconditions - User may create/update a plan and optionally save/load it
void WorkoutPlanBuilder::RunMenu() {
  WorkoutPlan plan;

  bool hasPlan = false;
  int choice = 0;

  do {
    cout << "===== Workout Plan Menu =====" << endl;
    cout << "1) View loaded exercises" << endl;
    cout << "2) Build an automatic 7-day plan" << endl;
    cout << "3) Build a custom 7-day plan" << endl;
    cout << "4) View current plan" << endl;
    cout << "5) Quit" << endl;

    choice = GetIntInRange(1, 5);

    if (choice == 1)
      DisplayLoadedExercises();

    else if (choice == 2) {
      plan = BuildWeeklyPlan();
      hasPlan = true;
      cout << "Automatic plan created." << endl;
    } else if (choice == 3) {
      plan = BuildWeeklyPlanInteractive();
      hasPlan = true;
    } else if (choice == 4) {
      if (!hasPlan)
        cout << "No current plan yet. Build or load one first." << endl;

      else
        plan.PrintPlan();
    }
  } while (choice != 5);
}