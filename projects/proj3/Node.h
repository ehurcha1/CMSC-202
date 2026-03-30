#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "PatientTreatment.h"
using namespace std;

// Name - Node
// Desc - Singly-linked list node storing a PatientTreatment
// Preconditions - None
// Postconditions - Supports next pointer and data accessors
class Node {
public:
  // Name - Node
  // Desc - Constructs a node with data and null next
  // Preconditions - PatientTreatment provided
  // Postconditions - Node created with m_next = nullptr
  Node(const PatientTreatment& d) : m_data(d), m_next(nullptr) {}
  // Name - GetNext
  // Desc - Returns next pointer
  // Preconditions - None
  // Postconditions - Returns m_next
  Node* GetNext() { return m_next; }
  // Name - SetNext
  // Desc - Sets the next pointer
  // Preconditions - Pointer provided
  // Postconditions - m_next updated
  void SetNext(Node* next) { m_next = next; }
  // Name - GetData
  // Desc - Returns a copy of the stored PatientTreatment
  // Preconditions - None
  // Postconditions - Returns m_data
  PatientTreatment GetData() { return m_data; }
private:
  PatientTreatment m_data; // Holds treatment data in node
  Node* m_next;            // Pointer to next node in linked list
};

#endif
