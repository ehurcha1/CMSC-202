#include "Snowboard.h"

Snowboard::Snowboard() {
  m_name = "Snowboard";
  m_item1 = "Bindings";
  m_item2 = "Step Ons";
  SetName("Snowboard");
}

Snowboard::~Snowboard() {}

Snowboard::Snowboard(string name, string item1, string item2) {
  m_name = name;
  m_item1 = item1;
  m_item2 = item2;
  SetName("Snowboard");
}

//DisplayItems Function to be implemented by students.
//Should override parent class DisplayItems()
void Snowboard::DisplayItems() {
  cout << "It's snowy items are" << m_item1 << " and " << m_item2 << "." << endl;
}

//SportActivity Function to be implemented by students.
//Should override parent class SportActivity()
void Snowboard::SportActivity() {
  cout << "Carves down the hill turning on heel and toes." << endl;
}