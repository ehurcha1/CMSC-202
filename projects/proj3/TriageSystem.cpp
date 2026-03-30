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

  cout << left  << setw(4)  << "#"
       << left  << setw(25) << "Treatment"
       << right << setw(6)  << "Doses"
       << right << setw(12) << "Unit Cost"
       << right << setw(12) << "Total" << "\n";
  cout << string(59, '-') << "\n";

  for (int i = 0; i < m_patient.GetTreatments().Count(); i++) {
    PatientTreatment pt = m_patient.At(i);
    const Treatment* t = m_catalog.FindById(pt.GetTreatmentId());
    string name = t ? t->GetName() : string("(unknown)");

    cout << left  << setw(4)  << (i + 1)
         << left  << setw(25) << name
         << right << setw(6)  << pt.GetDoses()
         << right << setw(12) << fixed << setprecision(2) << pt.GetUnitCost()
         << right << setw(12) << fixed << setprecision(2) << pt.GetTotalCost()
         << "\n";
  }

  cout << string(59, '-') << "\n";
  cout << right << setw(35) << "Subtotal:"
       << right << setw(24) << fixed << setprecision(2)
       << m_patient.GetSubtotal() << "\n";
  cout << right << setw(35) << "Facility Fee (15%):"
       << right << setw(24) << fixed << setprecision(2)
       << m_patient.GetFacilityFee() << "\n";
  cout << right << setw(35) << "Total:"
       << right << setw(24) << fixed << setprecision(2)
       << m_patient.GetTotal() << "\n";
}
