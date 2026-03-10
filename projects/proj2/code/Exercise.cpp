//Title: Exercise.cpp
//Author: Elliot Hurchalla
//Date: 3/7/2026
//Description: This is part of the project in CMSC 202.

#include "Exercise.h"

//Initialize with set zero values
Exercise::Exercise() {
    m_name = "";
    m_muscle = "";
    m_duration = 0;
}

//assign given values to m variables
Exercise::Exercise(string name, string muscle, int duration) {
    m_name = name;
    m_muscle = muscle;
    m_duration = duration;
}

//return m variables
string Exercise::GetName() const {return m_name;}
string Exercise::GetMuscle() const {return m_muscle;}
int Exercise::GetDuration() const {return m_duration;}