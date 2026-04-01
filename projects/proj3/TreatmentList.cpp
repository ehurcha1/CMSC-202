/*****************************************
** File: TreatmentList.cpp
** Project: CMSC 202 Project 3, Spring 2026
** Author: Elliot Hurchalla
** Date: 3/30/26
** Section: 14
** E-mail: ehurcha1@umbc.edu
**
** This file implements the TreatmentList class.
** This class manages a linked list of PatientTreatment objects.
**
******************************************/

#include "TreatmentList.h"
using namespace std;

// Name - TreatmentList
// Desc - Default constructor; initializes empty list
// Preconditions - None
// Postconditions - Empty list is created
TreatmentList::TreatmentList() { // Initialize empty list
  m_head = nullptr;              // Start with no nodes
  m_tail = nullptr;
  m_size = 0; // initialize size to zero to clear mem
}

// Name - ~TreatmentList
// Desc - Destructor; clears all nodes
// Preconditions - List may contain nodes
// Postconditions - Frees all nodes; list becomes empty
TreatmentList::~TreatmentList() {
  Clear(); // Pretty self-explanatory. Call clear to free all nodes.
}

// Name - PushBack
// Desc - Appends a PatientTreatment to the end of the list
// Preconditions - Valid PatientTreatment provided
// Postconditions - Size increases by one
void TreatmentList::PushBack(PatientTreatment item) {
  Node *newNode = new Node(item); // Create new node with item

  if (IsEmpty()) { // If list is empty, new node becomes head and tail
    m_head = newNode;
    m_tail = newNode;
  } else { // Otherwise, append to end and update tail
    m_tail->SetNext(newNode);
    m_tail = newNode;
  }
  m_size++; // Increase size by one
}

// Name - IsEmpty
// Desc - Indicates if the list has no nodes
// Preconditions - None
// Postconditions - Returns true if size is zero
bool TreatmentList::IsEmpty() {
  return m_size == 0; // List is empty if size is zero
}

// Name - Count
// Desc - Returns number of treatments in the list
// Preconditions - None
// Postconditions - Returns the size of the list
int TreatmentList::Count() {
  return m_size; // Return the number of treatments in the list
}

// Name - ComputeTotalCost
// Desc - Sums all treatment total costs in the list
// Preconditions - None
// Postconditions - Returns the total cost of all treatments
double TreatmentList::ComputeTotalCost() {
  double total = 0.0;
  Node *current = m_head;
  while (current != nullptr) {
    total += current->GetData().GetTotalCost();
    current = current->GetNext();
  }
  return total;
}

// Name - Clear
// Desc - Deletes all nodes and resets size
// Preconditions - None
// Postconditions - All nodes are deleted; size is reset to zero
void TreatmentList::Clear() {
  Node *current = m_head;
  while (current != nullptr) {
    Node *temp = current;
    current = current->GetNext();
    delete temp;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

// Name - At
// Desc - Returns the PatientTreatment at zero-based index
// Preconditions - Valid index
// Postconditions - Returns a copy of the item; returns empty PatientTreatment
// if out-of-bounds
PatientTreatment TreatmentList::At(int index) {
  if (index < 0 || index >= m_size) {
    return PatientTreatment(); // Return empty if out-of-bounds
  }
  Node *current = m_head;
  for (int i = 0; i < index; i++) {
    current = current->GetNext();
  }
  return current->GetData(); // Return a copy of the data at the index
}

// Name - RemoveAt
// Desc - Removes node at zero-based index
// Preconditions - Valid index
// Postconditions - Returns true if removed; size decreases one; returns false
// if out-of-bounds
bool TreatmentList::RemoveAt(int index) {
  if (index < 0 || index >= m_size) {
    return false; // Invalid index
  }
  Node *current = m_head;
  Node *previous = nullptr;
  for (int i = 0; i < index; i++) {
    previous = current;
    current = current->GetNext();
  }
  if (previous == nullptr) { // Removing head
    m_head = current->GetNext();
  } else {
    previous->SetNext(current->GetNext());
  }
  if (current == m_tail) { // Removing tail
    m_tail = previous;
  }
  delete current; // Free the removed node
  m_size--;       // Decrease size by one
  return true;    // Successfully removed
}