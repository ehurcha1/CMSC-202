#include "PatientTreatment.h"
using namespace std;

// Name - PatientTreatment
// Desc - Default constructor zeros all fields
// Preconditions - None
// Postconditions - PatientTreatment initialized to defaults
PatientTreatment::PatientTreatment() {
  m_treatmentId = 0;
  m_doses = 0;
  m_unitCost = 0.0;
}

// Name - PatientTreatment
// Desc - Overloaded constructor where you pass id, doses, and unitCost
// Preconditions - treatmentId, doses, unitCost provided
// Postconditions - Fields set and total cost computed
PatientTreatment::PatientTreatment(int treatmentId, int doses,
                                   double unitCost) {
  m_treatmentId = treatmentId;
  m_doses = doses;
  m_unitCost = unitCost;
}

// Name - GetTreatmentId
// Desc - Returns associated treatment id
// Preconditions - None
// Postconditions - Returns m_treatmentId
int PatientTreatment::GetTreatmentId() { return m_treatmentId; }

// Name - GetDoses
// Desc - Returns number of doses/units administered
// Preconditions - None
// Postconditions - Returns m_doses
int PatientTreatment::GetDoses() { return m_doses; }

// Name - GetUnitCost
// Desc - Returns cost per dose/unit
// Preconditions - None
// Postconditions - Returns m_unitCost
double PatientTreatment::GetUnitCost() { return m_unitCost; }

// Name - GetTotalCost
// Desc - Returns total cost as doses * unitCost
// Preconditions - None
// Postconditions - Returns m_doses * m_unitCost
double PatientTreatment::GetTotalCost() { return m_doses * m_unitCost; }
