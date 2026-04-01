/*****************************************
** File: TriageSystem.cpp
** Project: CMSC 202 Project 3, Spring 2026
** Author: Elliot Hurchalla
** Date: 3/31/26
** Section: 14
** E-mail: ehurcha1@umbc.edu
**
** This file implements the TriageSystem class.
** This class manages the ER triage system, including patient records and
* treatments.
**
******************************************/

#include "TriageSystem.h"

void TriageSystem::ShowTriageMenu() {
  cout << "\n== ER TRIAGE SYSTEM ==\n"
       << "1) View treatment catalog\n"
       << "2) Assign treatment to patient\n"
       << "3) Remove treatment from patient\n"
       << "4) View patient record\n"
       << "5) Discharge patient\n"
       << "0) Exit\n"
       << "Choice: ";
}

void TriageSystem::PrintPatientRecord() {
  cout << "\n== PATIENT RECORD #" << m_patient.GetPatientId() << " ==\n";
  if (m_patient.GetTreatments().IsEmpty()) {
    cout << "(no treatments assigned)\n";
    return;
  }

  cout << left << setw(4) << "#" << left << setw(25) << "Treatment" << right
       << setw(6) << "Doses" << right << setw(12) << "Unit Cost" << right
       << setw(12) << "Total" << "\n";
  cout << string(59, '-') << "\n";

  for (int i = 0; i < m_patient.GetTreatments().Count(); i++) {
    PatientTreatment pt = m_patient.At(i);
    const Treatment *t = m_catalog.FindById(pt.GetTreatmentId());
    string name = t ? t->GetName() : string("(unknown)");

    cout << left << setw(4) << (i + 1) << left << setw(25) << name << right
         << setw(6) << pt.GetDoses() << right << setw(12) << fixed
         << setprecision(2) << pt.GetUnitCost() << right << setw(12) << fixed
         << setprecision(2) << pt.GetTotalCost() << "\n";
  }

  cout << string(59, '-') << "\n";
  cout << right << setw(35) << "Subtotal:" << right << setw(24) << fixed
       << setprecision(2) << m_patient.GetSubtotal() << "\n";
  cout << right << setw(35) << "Facility Fee (15%):" << right << setw(24)
       << fixed << setprecision(2) << m_patient.GetFacilityFee() << "\n";
  cout << right << setw(35) << "Total:" << right << setw(24) << fixed
       << setprecision(2) << m_patient.GetTotal() << "\n";
}

// Name - TriageSystem
// Desc - Default constructor; initializes patient id using STARTING_PATIENT_ID
// Preconditions - None
// Postconditions - TriageSystem is ready to load a catalog and admit patients
TriageSystem::TriageSystem() {
  m_nextPatientId =
      STARTING_PATIENT_ID; // Set next patient id to starting value
  AdmitNewPatient();       // Initialize first patient record
}

// Name - LoadCatalog
// Desc - Loads treatment entries from a CSV file (id,name,cost)
// Preconditions - Valid filename; file is accessible
// Postconditions - Treatments loaded into TreatmentCatalog
void TriageSystem::LoadCatalog(string filename) {
  m_catalog.LoadCatalog(filename); // Load treatments
}
// Name - Run
// Desc - Main loop for the triage system (displays menu and calls functions)
//        1. View catalog  2. Assign treatment  3. Remove treatment
//        4. View patient record  5. Discharge patient  0. Exit
// Preconditions - Catalog should be loaded
// Postconditions - Handles user choices until exit
void TriageSystem::Run() {
  int choice;
  do {
    ShowTriageMenu();
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      m_catalog.PrintCatalog(); // View treatment catalog
      break;
    case 2:
      AssignTreatmentFlow(); // Assign treatment to patient
      break;
    case 3:
      RemoveTreatmentFlow(); // Remove treatment from patient
      break;
    case 4:
      m_patient.RecomputeTotals();
      PrintPatientRecord(); // View patient record
      break;
    case 5:
      DischargeFlow(); // Discharge patient
      break;
    case 0:
      cout << "Thank you for using Hospital Triage" << endl;
      break;
    default:
      cout << "Unknown choice." << endl;
      break;
    }
  } while (choice != 0);
}

// Start off private functions

// Name - AdmitNewPatient
// Desc - Clears current treatments and initializes a new patient record
// Preconditions - None
// Postconditions - New empty patient with id set
void TriageSystem::AdmitNewPatient() {
  m_patient.ClearTreatments();             // Clear treatments
  m_patient.SetPatientId(m_nextPatientId); // Set patient id to next
  m_nextPatientId++;                       // Increment next patient id
}

// Name - AssignTreatmentFlow
// Desc - Prompts for a treatment id and doses, then assigns to patient
// Preconditions - Catalog must contain loaded treatments
// Postconditions - Adds treatment when input is valid
void TriageSystem::AssignTreatmentFlow() { // Show catalog and prompt for
                                           // treatment and doeses
  m_catalog.PrintCatalog();
  int id, doses;
  cout << "Enter treatment ID: ";
  cin >> id;
  cout << "Enter number of doses/units: ";
  cin >> doses;

  if (m_patient.AddTreatmentById(m_catalog, id, doses)) {
    cout << "Treatment assigned." << endl;
  } else {
    cout << "Invalid treatment ID or dose count." << endl;
  }
}

// Name - RemoveTreatmentFlow
// Desc - Shows current treatments and removes a selected one by index
// Preconditions - Patient has at least one treatment
// Postconditions - Removes selected treatment when valid index entered
void TriageSystem::RemoveTreatmentFlow() { // Shows treatments and prompt to
                                           // remove
  if (m_patient.GetTreatments().IsEmpty()) {
    cout << "No treatments to remove." << endl;
    return;
  }

  m_patient.RecomputeTotals();
  PrintPatientRecord();

  int treatmentNumber = 0;
  cout << "Remove which treatment #? ";
  cin >> treatmentNumber;

  if (m_patient.RemoveAt(treatmentNumber - 1)) {
    cout << "Removed treatment " << treatmentNumber << "." << endl;
  } else {
    cout << "Invalid treatment number." << endl;
  }
}

// Name - DischargeFlow
// Desc - If patient has treatments, prints final record and admits next patient
//        Cannot discharge if no treatments added.
// Preconditions - Any state of patient allowed
// Postconditions - Current patient discharged; new patient admitted
void TriageSystem::DischargeFlow() { // Print record and admit new patient
  if (m_patient.GetTreatments().IsEmpty()) {
    cout << "No treatments assigned. Patient cannot be discharged." << endl;
    return;
  }

  m_patient.RecomputeTotals();
  PrintPatientRecord();
  cout << "\n*** PATIENT DISCHARGED ***\n" << endl;
  AdmitNewPatient();
}