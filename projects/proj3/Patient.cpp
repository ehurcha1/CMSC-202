#include "Patient.h"
using namespace std;

// Name - Patient
// Desc - Default constructor initializes fields to 0
// Preconditions - None
// Postconditions - Patient ready for use
Patient::Patient() {   // Initialize fields to default values
  m_patientId = 0;     // Patient number/id
  m_subtotal = 0.0;    // Sum of treatment costs before fees
  m_facilityFee = 0.0; // Additional fee based on subtotal
  m_total = 0.0;       // Total cost including treatments and fees
}

// Name - GetPatientId
// Desc - Returns the patient number
// Preconditions - None
// Postconditions - Returns m_patientId
int Patient::GetPatientId() { return m_patientId; }

// Name - GetSubtotal
// Desc - Returns subtotal of treatment costs
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_subtotal
double Patient::GetSubtotal() { return m_subtotal; }

// Name - GetFacilityFee
// Desc - Returns computed facility fee
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_facilityFee
double Patient::GetFacilityFee() { return m_facilityFee; }

// Name - GetTotal
// Desc - Returns total (subtotal + facility fee)
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_total
double Patient::GetTotal() { return m_total; }

// Name - GetTreatments
// Desc - Returns a reference to the treatment list
// Preconditions - None
// Postconditions - Returns reference to m_treatments
TreatmentList &Patient::GetTreatments() { return m_treatments; }

// Name - SetPatientId
// Desc - Sets patient number
// Preconditions - Valid id provided
// Postconditions - m_patientId updated
void Patient::SetPatientId(int id) { m_patientId = id; }

// Name - AddTreatment
// Desc - Adds a prepared PatientTreatment row
// Preconditions - Treatment is valid
// Postconditions - Treatment appended to list
void Patient::AddTreatment(PatientTreatment row) { m_treatments.PushBack(row); }

// Name - ClearTreatments
// Desc - Removes all treatments
// Preconditions - None
// Postconditions - List cleared
void Patient::ClearTreatments() { m_treatments.Clear(); }

// Name - RecomputeTotals
// Desc - Recalculates subtotal, facility fee, and total based on current
// treatments Preconditions - Treatments may exist; costs should be valid
// Postconditions - m_subtotal, m_facilityFee, and m_total updated
void Patient::RecomputeTotals() {
  m_subtotal = m_treatments.ComputeTotalCost(); // Sum of treatment costs
  m_facilityFee = m_subtotal * 0.15;    // Facility fee is 15% of subtotal
  m_total = m_subtotal + m_facilityFee; // Total is subtotal plus facility fee
}