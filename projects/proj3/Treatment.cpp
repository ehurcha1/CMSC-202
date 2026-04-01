/*****************************************
** File: Treatment.cpp
** Project: CMSC 202 Project 3, Spring 2026
** Author: Elliot Hurchalla
** Date: 3/29/26
** Section: 14
** E-mail: ehurcha1@umbc.edu
**
** This file implements the Treatment class.
** This class creates the treatment's id, name, and cost.
**
******************************************/

#include "Treatment.h"
using namespace std;

// Name - Treatment
// Desc - Default constructor; zero/empty fields
// Preconditions - None
// Postconditions - Treatment created with default values
Treatment::Treatment() {
  m_id = 0;
  m_name = "";
  m_cost = 0.0;
}

// Name - Treatment
// Desc - Overloaded constructor
// Preconditions - Valid id, name, cost provided
// Postconditions - Treatment initialized with given values
Treatment::Treatment(int id, string name, double cost) {
  m_id = id;
  m_name = name;
  m_cost = cost;
}

// Name - GetId
// Desc - Returns the treatment id
// Preconditions - None
// Postconditions - Returns m_id
int Treatment::GetId() const { return m_id; }

// Name - GetName
// Desc - Returns the treatment name
// Preconditions - None
// Postconditions - Returns m_name
string Treatment::GetName() const { return m_name; }

// Name - GetCost
// Desc - Returns the treatment cost
// Preconditions - None
// Postconditions - Returns m_cost
double Treatment::GetCost() const { return m_cost; }
