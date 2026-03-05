#include "FarmersMarket.h"

/*************************************************************** 
** File: FarmersMarket.cpp
** Description: This file contains the FarmersMarket function definitions
***************************************************************/

// Constructor - Already implemented for you
FarmersMarket::FarmersMarket() {
  cout << "It is your first day managing the UMBC Farmers Market.\n";
  cout << "Time to sell some veggies!\n";
  m_revenue = 0; // money made so far
  m_corn = 0; // corn available
  m_cornPrice = 0; // price for a single corn
  m_carrot = 0; // number of carrots available
  m_carrotPrice = 0; // price for a single carrot
}

// Getter for m_corn already implemented for you
int FarmersMarket::GetCornCount() const {return m_corn;}

// Implement Getters here (get carrot count, corn price,
//     carrot price, revenue)
// Don't forget the const keyword after the ()
int FarmersMarket::GetCarrotCount() const {return m_carrot;}
float FarmersMarket::GetCornPrice() const {return m_cornPrice;}
float FarmersMarket::GetCarrotPrice() const {return m_carrotPrice;}
float FarmersMarket::GetRevenue() const {return m_revenue;}





// Implement Setters here (set carrot count, corn price,
//   carrot price, revenue)

// Setter for m_cornCobs already implemented for you
void FarmersMarket::SetCornCount(int corn) {
  m_corn = corn;
}
// Implement Set Carrot Count
void FarmersMarket::SetCarrotCount(int carrot) {
  m_carrot = carrot;
}


// Implement Set Corn Price
void FarmersMarket::SetCornPrice(float price) {
  m_cornPrice = price;
}


// Implement Set Carrot Price
void FarmersMarket::SetCarrotPrice(float price) {
  m_carrotPrice = price;
}


// Implement Set Revenue
void FarmersMarket::SetRevenue(float revenue) {
  m_revenue = revenue;
}



// Implement SellCorn here
void FarmersMarket::SellCorn() {
  if (m_corn > 0) {
    m_corn--;
    m_revenue += m_cornPrice;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "You just sold a corn for $" << m_cornPrice << endl;
  }
  else {
    cout << "Sorry, you are out of corn!" << endl;
  }
}



// Implement SellCarrot here
void FarmersMarket::SellCarrot() {
  if (m_carrot > 0) {
    m_carrot--;
    m_revenue += m_carrotPrice;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "You just sold a carrot for $" << m_carrotPrice << endl;
  }
  else {
    cout << "Sorry, you are out of carrots!" << endl;
  }
}




// SellAll already implemented for you
void FarmersMarket::SellAll(){
  double revenue = m_corn * m_cornPrice +
    m_carrot * m_carrotPrice;
  m_revenue += revenue;
  m_corn = 0;
  m_carrot = 0;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "You just sold veggies with a total value of: $"
       << revenue << endl;
}
