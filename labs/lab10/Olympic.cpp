#include "Olympic.h"


Olympic::Olympic() {
  m_name = "Olympic";
}

Olympic::~Olympic() {}

string Olympic::GetName() {
  return m_name;
}

void Olympic::SetName(string name) {
  m_name = name;
}

//PrintName Function to be implemented by students.
//Should output Olympic Sport: and then the name
void Olympic::PrintName() {
  cout << "Olympic Sport: " << m_name << endl;
}