#include "Ski.h"

Ski::Ski() {
  m_name = "Ski";
  m_item1 = "Boots";
  m_item2 = "Poles";
  SetName("Ski");
}

Ski::~Ski() {}

Ski::Ski(string name, string item1, string item2) {
  m_name = name;
  m_item1 = item1;
  m_item2 = item2;
  SetName("Ski");
}

// DisplayItems Function to be implemented by students.
// Should override parent class DisplayItems()
void Ski::DisplayItems() {
  cout << "It's snowy items are" << m_item1 << " and " << m_item2 << "." << endl;
}


// SportActivity Function to be implemented by students.
// Should override parent class SportActivity()
void SportActivity() {
  cout << "They ski down at top speed with snow flying behind them!" <<endl;
}

