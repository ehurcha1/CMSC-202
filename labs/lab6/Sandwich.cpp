#include "Sandwich.h"


Sandwich::Sandwich() {
    m_name = ""; //name of customer
    m_type = 0; //type of sandwich using enums
}

Sandwich::Sandwich(string name, int type) {
    m_name = name; //customer name
    m_type = type; //sandwich 
}

string Sandwich::GetName() {
    return m_name; //return customer name
}

int Sandwich::GetType() {
    return m_type; //return sandwich type
}

void Sandwich::SetName(string name) {
    m_name = name; //set customer name
}

void Sandwich::SetType(int type) {
    m_type = type; //set sandwich type
}