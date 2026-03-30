#ifndef TREATMENT_CATALOG_H
#define TREATMENT_CATALOG_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Treatment.h"
using namespace std;

//***Constants***
const int WID_ID   = 5;  // Width for id column
const int WID_NAME = 25; // Width for name column
const int WID_COST = 12; // Width for cost column

// Name - TreatmentCatalog
// Desc - Stores a list of Treatments possible
// Preconditions - None
// Postconditions - Can load/print catalog and find treatments by id
class TreatmentCatalog {
public:
  // Name - FindById
  // Desc - Returns pointer to Treatment with matching id or nullptr
  // Preconditions - Catalog loaded; id provided
  // Postconditions - Pointer returned or nullptr if not found
  const Treatment* FindById(int id) const;
  // Name - LoadCatalog
  // Desc - Loads treatments from a file (id,name,and cost)
  // Preconditions - Valid filename provided
  // Postconditions - Treatments appended to catalog
  void LoadCatalog(string filename);
  // Name - PrintCatalog
  // Desc - Prints all treatments as a formatted table
  // Preconditions - Items may exist
  // Postconditions - Outputs catalog to console
  void PrintCatalog();
private:
  vector<Treatment> m_treatments; // Vector of all treatments available
};

#endif
