/*****************************************
** File: Patient.cpp
** Project: CMSC 202 Project 3, Spring 2026
** Author: Elliot Hurchalla
** Date: 3/31/26
** Section: 14
** E-mail: ehurcha1@umbc.edu
**
** This file implements the Patient class.
** This class manages a patient's treatments and costs.
**
******************************************/

#include "Patient.h"
using namespace std;

// Name - Patient
// Desc - Default constructor initializes fields to 0
// Preconditions - None
// Postconditions - Patient ready for use
Patient::Patient() { // Set zeros
  m_patientId = 0;
  m_subtotal = 0.0;
  m_facilityFee = 0.0;
  m_total = 0.0;
}

// Name - GetPatientId
// Desc - Returns the patient number
// Preconditions - None
// Postconditions - Returns m_patientId
int Patient::GetPatientId() { // Return patient ID
  return m_patientId;
}

// Name - GetSubtotal
// Desc - Returns subtotal of treatment costs
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_subtotal
double Patient::GetSubtotal() { // Return costs
  return m_subtotal;
}

// Name - GetFacilityFee
// Desc - Returns computed facility fee
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_facilityFee
double Patient::GetFacilityFee() { // Return faciliy fee
  return m_facilityFee;
}

// Name - GetTotal
// Desc - Returns total (subtotal + facility fee)
// Preconditions - RecomputeTotals has been called for accuracy
// Postconditions - Returns m_total
double Patient::GetTotal() { // total cost
  return m_total;
}

// Name - GetTreatments
// Desc - Returns a reference to the treatment list
// Preconditions - None
// Postconditions - Returns reference to m_treatments
TreatmentList &Patient::GetTreatments() { // ref to treatment list
  return m_treatments;
}

// Name - SetPatientId
// Desc - Sets patient number
// Preconditions - Valid id provided
// Postconditions - m_patientId updated
void Patient::SetPatientId(int id) { // Set patient ID
  m_patientId = id;
}

// Name - AddTreatment
// Desc - Adds a prepared PatientTreatment row
// Preconditions - Treatment is valid
// Postconditions - Treatment appended to list
void Patient::AddTreatment(PatientTreatment row) { // Add to list
  m_treatments.PushBack(row);
}

// Name - ClearTreatments
// Desc - Removes all treatments
// Preconditions - None
// Postconditions - List cleared
void Patient::ClearTreatments() { // Clear list
  m_treatments.Clear();
}

// Name - AddTreatmentById
// Desc - Looks up cost in catalog and appends a treatment with doses
// Preconditions - Catalog loaded; id exists; doses > 0
// Postconditions - Treatment added and true returned; otherwise false
bool Patient::AddTreatmentById(const TreatmentCatalog &catalog, int id,
                               int doses) { // Add treatment based on ID
  const Treatment *t = catalog.FindById(id);
  if (t == nullptr || doses <= 0) {
    return false;
  }
  double doseCost = t->GetCost();
  PatientTreatment pt(id, doses, doseCost);
  AddTreatment(pt);
  return true;
}

// Name - At
// Desc - Returns the PatientTreatment at zero-based index
// Preconditions - 0 <= index < Count()
// Postconditions - Returns a copy (default if out-of-range)
PatientTreatment Patient::At(int index) { // Return index for treatment
  return m_treatments.At(index);
}

// Name - RemoveAt
// Desc - Removes a treatment at zero-based index
// Preconditions - 0 <= index < Count()
// Postconditions - Returns true if removed
bool Patient::RemoveAt(int index) { // Remove treatment at index
  return m_treatments.RemoveAt(index);
}

// Name - RecomputeTotals
// Desc - Recalculates subtotal, facility fee, and total based on current
// treatments Preconditions - Treatments may exist; costs should be valid
// Postconditions - m_subtotal, m_facilityFee, and m_total updated
void Patient::RecomputeTotals() {
  m_subtotal = m_treatments.ComputeTotalCost();
  m_facilityFee = m_subtotal * FACILITY_FEE_RATE; // Facility fee
  m_total = m_subtotal + m_facilityFee;
}