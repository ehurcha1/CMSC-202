#ifndef TREATMENT_H
#define TREATMENT_H

#include <string>
using namespace std;

// Name - Treatment
// Desc - Represents a medical treatment in the ER catalog (id, name, cost)
// Preconditions - None
// Postconditions - Stores and exposes basic fields
class Treatment {
public:
  // Name - Treatment
  // Desc - Default constructor; zero/empty fields
  // Preconditions - None
  // Postconditions - Treatment created with default values
  Treatment();
  // Name - Treatment
  // Desc - Overloaded constructor
  // Preconditions - Valid id, name, cost provided
  // Postconditions - Treatment initialized with given values
  Treatment(int id, string name, double cost);
  // Name - GetId
  // Desc - Returns the treatment id
  // Preconditions - None
  // Postconditions - Returns m_id
  int GetId() const;
  // Name - GetName
  // Desc - Returns the treatment name
  // Preconditions - None
  // Postconditions - Returns m_name
  string GetName() const;
  // Name - GetCost
  // Desc - Returns the treatment cost
  // Preconditions - None
  // Postconditions - Returns m_cost
  double GetCost() const;
private:
  int m_id;      // Unique ID for treatment
  string m_name; // Name of treatment
  double m_cost; // Cost of treatment
};

#endif
