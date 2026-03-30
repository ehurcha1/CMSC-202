#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "TreatmentList.h"
#include "TreatmentCatalog.h"
using namespace std;

//***Constant***
const double FACILITY_FEE_RATE = 0.15; //Percentage adder to subtotal (15% added)

// Name - Patient
// Desc - Represents an ER patient that can have many treatments (and costs)
// Preconditions - None
// Postconditions - Stores patient data and treatment records
class Patient {
public:
  // Name - Patient
  // Desc - Default constructor initializes fields to 0
  // Preconditions - None
  // Postconditions - Patient ready for use
  Patient();
  // Name - GetPatientId
  // Desc - Returns the patient number
  // Preconditions - None
  // Postconditions - Returns m_patientId
  int GetPatientId();
  // Name - GetSubtotal
  // Desc - Returns subtotal of treatment costs
  // Preconditions - RecomputeTotals has been called for accuracy
  // Postconditions - Returns m_subtotal
  double GetSubtotal();
  // Name - GetFacilityFee
  // Desc - Returns computed facility fee
  // Preconditions - RecomputeTotals has been called for accuracy
  // Postconditions - Returns m_facilityFee
  double GetFacilityFee();
  // Name - GetTotal
  // Desc - Returns total (subtotal + facility fee)
  // Preconditions - RecomputeTotals has been called for accuracy
  // Postconditions - Returns m_total
  double GetTotal();
  // Name - GetTreatments
  // Desc - Returns a reference to the treatment list
  // Preconditions - None
  // Postconditions - Returns reference to m_treatments
  TreatmentList& GetTreatments();
  // Name - SetPatientId
  // Desc - Sets patient number
  // Preconditions - Valid id provided
  // Postconditions - m_patientId updated
  void SetPatientId(int id);
  // Name - AddTreatment
  // Desc - Adds a prepared PatientTreatment row
  // Preconditions - Treatment is valid
  // Postconditions - Treatment appended to list
  void AddTreatment(PatientTreatment row);
  // Name - ClearTreatments
  // Desc - Removes all treatments
  // Preconditions - None
  // Postconditions - List cleared
  void ClearTreatments();
  // Name - AddTreatmentById
  // Desc - Looks up cost in catalog and appends a treatment with doses
  // Preconditions - Catalog loaded; id exists; doses > 0
  // Postconditions - Treatment added and true returned; otherwise false
  bool AddTreatmentById(const TreatmentCatalog& catalog, int id, int doses);
  // Name - At
  // Desc - Returns the PatientTreatment at zero-based index
  // Preconditions - 0 <= index < Count()
  // Postconditions - Returns a copy (default if out-of-range)
  PatientTreatment At(int index);
  // Name - RemoveAt
  // Desc - Removes a treatment at zero-based index
  // Preconditions - 0 <= index < Count()
  // Postconditions - Returns true if removed
  bool RemoveAt(int index);
  // Name - RecomputeTotals
  // Desc - Refreshes subtotal, facility fee, and total
  // Preconditions - FACILITY_FEE_RATE defined
  // Postconditions - m_subtotal, m_facilityFee, and m_total updated
  void RecomputeTotals();
private:
  int m_patientId;            // Unique patient ID
  double m_subtotal;          // Calculated treatment subtotal
  double m_facilityFee;       // Calculated facility fee
  double m_total;             // Total calculated amount
  TreatmentList m_treatments; // Linked list of patient treatments
};

#endif
