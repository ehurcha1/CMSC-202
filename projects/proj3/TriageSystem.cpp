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
  m_patient.SetPatientId(STARTING_PATIENT_ID); // Set initial patient id
}

// Name - LoadCatalog
// Desc - Loads treatment entries from a CSV file (id,name,cost)
// Preconditions - Valid filename; file is accessible
// Postconditions - Treatments loaded into TreatmentCatalog
void TriageSystem::LoadCatalog(string filename) {
  m_catalog.LoadCatalog(filename); // Load treatments from file into catalog
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
    ShowTriageMenu(); // Display menu options
    cin >> choice;    // Get user choice
    cin.ignore();     // Clear newline from input buffer

    switch (choice) {
    case 1:
      // View catalog
      break;
    case 2:
      // Assign treatment
      break;
    case 3:
      // Remove treatment
      break;
    case 4:
      // View patient record
      break;
    case 5:
      // Discharge patient
      break;
    case 0:
      // Exit
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != 0);
}