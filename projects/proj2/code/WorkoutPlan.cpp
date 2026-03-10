//Title: WorkoutPlan.cpp
//Author: Elliot Hurchalla
//Date: 3/7/2026
//Description: This is part of the project in CMSC 202.

#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan() {
    m_dayNames[0] = "Monday";
    m_dayNames[1] = "Tuesday";
    m_dayNames[2] = "Wednesday";
    m_dayNames[3] = "Thursday";
    m_dayNames[4] = "Friday";
    m_dayNames[5] = "Saturday";
    m_dayNames[6] = "Sunday";
}

void WorkoutPlan::SetDayExercise(int day, const Exercise &exercise) {
    if (day >= 0 && day < 7) {
        m_weekPlan[day] = exercise;
    }
}

Exercise WorkoutPlan::GetDayExercise(int day) const {
    if (day >= 0 && day < 7) {
        return m_weekPlan[day];
    }
    return Exercise();
}

void WorkoutPlan::PrintPlan() const {
    for (int i = 0; i >= 0 && i < 7; i++) {
        cout << "=== Your 7-Day CMSC 202 Workout Plan ===" << endl;
        cout << m_dayNames[i] << ":"
        << m_weekPlan[i].GetName() << " ("
        << m_weekPlan[i].GetMuscle() << ", "
        << m_weekPlan[i].GetDuration() << " min)"
        << endl;
    }
}
