#ifndef TREATMENT_LIST_H
#define TREATMENT_LIST_H

#include "PatientTreatment.h"
#include "Node.h"
using namespace std;

// Name - TreatmentList
// Desc - Singly-linked list that stores PatientTreatment rows
// Preconditions - None
// Postconditions - Manages dynamic nodes for patient treatments
class TreatmentList {
public:
  // Name - TreatmentList
  // Desc - Default constructor; initializes empty list
  // Preconditions - None
  // Postconditions - Empty list is created
  TreatmentList();
  // Name - ~TreatmentList
  // Desc - Destructor; clears all nodes
  // Preconditions - List may contain nodes
  // Postconditions - Frees all nodes; list becomes empty
  ~TreatmentList();
  // Name - PushBack
  // Desc - Appends a PatientTreatment to the end of the list
  // Preconditions - Valid PatientTreatment provided
  // Postconditions - Size increases by one
  void PushBack(PatientTreatment item);
  // Name - IsEmpty
  // Desc - Indicates if the list has no nodes
  // Preconditions - None
  // Postconditions - Returns true if size is zero
  bool IsEmpty();
  // Name - Count
  // Desc - Returns number of treatments in the list
  // Preconditions - None
  // Postconditions - Returns m_size
  int Count();
  // Name - ComputeTotalCost
  // Desc - Sums all treatment total costs in the list
  // Preconditions - Items may exist with valid total costs
  // Postconditions - Returns sum as double
  double ComputeTotalCost();
  // Name - Clear
  // Desc - Deletes all nodes and resets size
  // Preconditions - None
  // Postconditions - List becomes empty
  void Clear();
  // Name - At
  // Desc - Returns the PatientTreatment at zero-based index
  // Preconditions - Valid index
  // Postconditions - Returns a copy of the item; returns empty PatientTreatment if out-of-bounds
  PatientTreatment At(int index);
  // Name - RemoveAt
  // Desc - Removes node at zero-based index
  // Preconditions - Valid index
  // Postconditions - Returns true if removed; size decreases one; returns false if out-of-bounds
  bool RemoveAt(int index);
private:
  Node* m_head; // First node in linked list
  Node* m_tail; // Last node in linked list
  int m_size;   // Number of nodes in linked list
};

#endif
