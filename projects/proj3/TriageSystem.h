#ifndef TRIAGE_SYSTEM_H
#define TRIAGE_SYSTEM_H

#include <string>
#include <iostream>
#include <iomanip>
#include "TreatmentCatalog.h"
#include "Patient.h"
using namespace std;

//***Constant***
const int STARTING_PATIENT_ID = 2001; //Starting id

// Name - TriageSystem
// Desc - ER triage system that manages the treatment catalog and current patient
// Preconditions - Catalog file present when loading
// Postconditions - Allows assigning/removing treatments, viewing patient record, and discharge
class TriageSystem {
public:
  // Name - TriageSystem
  // Desc - Default constructor; initializes patient id using STARTING_PATIENT_ID
  // Preconditions - None
  // Postconditions - TriageSystem is ready to load a catalog and admit patients
  TriageSystem();
  // Name - LoadCatalog
  // Desc - Loads treatment entries from a CSV file (id,name,cost)
  // Preconditions - Valid filename; file is accessible
  // Postconditions - Treatments loaded into TreatmentCatalog
  void LoadCatalog(string filename);
  // Name - Run
  // Desc - Main loop for the triage system (displays menu and calls functions)
  //        1. View catalog  2. Assign treatment  3. Remove treatment
  //        4. View patient record  5. Discharge patient  0. Exit
  // Preconditions - Catalog should be loaded
  // Postconditions - Handles user choices until exit
  void Run();
private:
  // Name - AdmitNewPatient
  // Desc - Clears current treatments and initializes a new patient record
  // Preconditions - None
  // Postconditions - New empty patient with id set
  void AdmitNewPatient();
  // Name - ShowTriageMenu
  // Desc - Displays the triage system command list (1-5 and 0 is exit)
  // Preconditions - None
  // Postconditions - Outputs menu of choices to console
  void ShowTriageMenu();
  // Name - PrintPatientRecord
  // Desc - Prints the current patient's treatments and billing summary
  // Preconditions - Patient may have zero or more treatments
  // Postconditions - Outputs treatment lines and totals to console
  void PrintPatientRecord();
  // Name - AssignTreatmentFlow
  // Desc - Prompts for a treatment id and doses, then assigns to patient
  // Preconditions - Catalog must contain loaded treatments
  // Postconditions - Adds treatment when input is valid
  void AssignTreatmentFlow();
  // Name - RemoveTreatmentFlow
  // Desc - Shows current treatments and removes a selected one by index
  // Preconditions - Patient has at least one treatment
  // Postconditions - Removes selected treatment when valid index entered
  void RemoveTreatmentFlow();
  // Name - DischargeFlow
  // Desc - If patient has treatments, prints final record and admits next patient
  //        Cannot discharge if no treatments added.
  // Preconditions - Any state of patient allowed
  // Postconditions - Current patient discharged; new patient admitted
  void DischargeFlow();
  TreatmentCatalog m_catalog; // Manages treatment catalog
  Patient m_patient;          // Current patient (one at a time)
  int m_nextPatientId;        // Tracks next patient id
};

#endif
