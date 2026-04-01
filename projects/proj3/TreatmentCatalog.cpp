/*****************************************
** File: TreatmentCatalog.cpp
** Project: CMSC 202 Project 3, Spring 2026
** Author: Elliot Hurchalla
** Date: 3/29/26
** Section: 14
** E-mail: ehurcha1@umbc.edu
**
** This file implements the TreatmentCatalog class.
** This class manages a collection of Treatment objects.
**
******************************************/

#include "TreatmentCatalog.h"
#include <string>
using namespace std;

// Name - FindById
// Desc - Returns pointer to Treatment with matching id or nullptr
// Preconditions - Catalog loaded; id provided
// Postconditions - Pointer returned or nullptr if not found
const Treatment *TreatmentCatalog::FindById(int id) const {
  for (int i = 0; i < (int)m_treatments.size(); i++) { // Cycle through
    if (m_treatments[i].GetId() == id) {               // Found a match
      return &m_treatments[i];
    }
  }
  return nullptr;
}

// Name - LoadCatalog
// Desc - Loads treatments from a file (id,name,and cost)
// Preconditions - Valid filename provided
// Postconditions - Treatments appended to catalog
void TreatmentCatalog::LoadCatalog(string filename) { // Open file to read
  ifstream inputFile(filename);

  string idString;
  string name;
  string costString;

  while (getline(inputFile, idString, ',')) {
    getline(inputFile, name, ',');
    getline(inputFile, costString);

    int id = stoi(idString);        // Convert id to int
    double cost = stod(costString); // Convert cost to double

    Treatment t(id, name, cost); // Create treatment
    m_treatments.push_back(t);   // Add to catalog
  }
}

// Name - PrintCatalog
// Desc - Prints all treatments as a formatted table
// Preconditions - Catalog loaded
// Postconditions - Treatments printed to console
void TreatmentCatalog::PrintCatalog() {         // Print header
  cout << left << setw(WID_ID) << "ID"          // Id column aligned left
       << left << setw(WID_NAME) << "Treatment" // Name column aligned left
       << right << setw(WID_COST) << "Cost"
       << endl; // Cost column aligned right
  cout << string(WID_ID + WID_NAME + WID_COST, '-') << endl; // Print line

  for (int i = 0; i < (int)m_treatments.size();
       i++) { // Cycle through treatments
    const Treatment &t = m_treatments[i];
    cout << left << setw(WID_ID) << t.GetId()     // Id aligned left
         << left << setw(WID_NAME) << t.GetName() // Name aligned left
         << "$" << right << setw(WID_COST - 1) << fixed << setprecision(2)
         << t.GetCost() << endl;
  }
}