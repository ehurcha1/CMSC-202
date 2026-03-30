#ifndef PATIENT_TREATMENT_H
#define PATIENT_TREATMENT_H

#include <iostream>
using namespace std;

// Name - PatientTreatment
// Desc - Represents a treatment
// Preconditions - None
// Postconditions - Can compute and store total costs
class PatientTreatment {
public:
  // Name - PatientTreatment
  // Desc - Default constructor zeros all fields
  // Preconditions - None
  // Postconditions - PatientTreatment initialized to defaults
  PatientTreatment();
  // Name - PatientTreatment
  // Desc - Overloaded constructor where you pass id, doses, and unitCost
  // Preconditions - treatmentId, doses, unitCost provided
  // Postconditions - Fields set and total cost computed
  PatientTreatment(int treatmentId, int doses, double unitCost);
  // Name - GetTreatmentId
  // Desc - Returns associated treatment id
  // Preconditions - None
  // Postconditions - Returns m_treatmentId
  int GetTreatmentId();
  // Name - GetDoses
  // Desc - Returns number of doses/units administered
  // Preconditions - None
  // Postconditions - Returns m_doses
  int GetDoses();
  // Name - GetUnitCost
  // Desc - Returns cost per dose/unit
  // Preconditions - None
  // Postconditions - Returns m_unitCost
  double GetUnitCost();
  // Name - GetTotalCost
  // Desc - Returns total cost as doses * unitCost
  // Preconditions - None
  // Postconditions - Returns computed total cost
  double GetTotalCost();
private:
  int m_treatmentId; // ID of the assigned treatment
  int m_doses;       // Number of doses/units administered
  double m_unitCost; // Cost per dose/unit
};

#endif
