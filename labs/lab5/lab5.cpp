/************************************************************************
** File: lab5.cpp
** Description: Uses a Farmers Market to demonstrate how classes work in C++
************************************************************************/

#include "FarmersMarket.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Global Constants
const int NUM_CORN = 44; // Number of starting corn
const int NUM_CARROT = 28; // Number of starting carrots
const double PRICE_CORN = 2.99; // Price per corn
const double PRICE_CARROT = 5.99; // Price per carrot

// Declare DisplayInfo here (provided)
void displayInfo(const FarmersMarket& myMarket);

int main() {
  // Creates FarmersMarket object
  FarmersMarket myMarket;

  // Use setters to populate member variables of the FarmersMarket
  // Use constants to populate corn count and price
  myMarket.SetCornCount(NUM_CORN);
  myMarket.SetCornPrice(PRICE_CORN);

  // Use constants to populate carrot count and price
  myMarket.SetCarrotCount(NUM_CARROT);
  myMarket.SetCarrotPrice(PRICE_CARROT);
  
  // Displays inventory at the farmers market
  displayInfo(myMarket);

  // Sell a single corn (and tells user about the sale)
  cout << "\nSelling one CORN!" << endl;
  myMarket.SellCorn();
  displayInfo(myMarket);

  // Sell a single carrot (and tells user about the sale)
  cout << "\nSelling one CARROT!" << endl;
  myMarket.SellCarrot();
  displayInfo(myMarket);

  // Sells the rest of the items and displays overall revenue
  cout << "\nSelling all our inventory!" << endl;
  myMarket.SellAll();

  // Displays the total revenue after selling all of the items
  cout << "\nToday's Revenue: $" << myMarket.GetRevenue() << "\n" << endl;
  
  return 0;
}

// Implement displayInfo here
// Displays corn and carrots available (Getters)
// Displays corn and carrot cost per item (Getters)
// Displays current revenue at store (Getter)
// Hint: Use fixed and cout.precision(2) or setprecision(2) for currency
void displayInfo(const FarmersMarket& myMarket){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "Corn Available: " << myMarket.GetCornCount() << endl;
  cout << "Carrots Available: " << myMarket.GetCarrotCount() << endl;
  cout << "Each Corn Costs: $" << myMarket.GetCornPrice() << endl;
  cout << "Each Carrot Costs: $" << myMarket.GetCarrotPrice() << endl;
  cout << "Current Revenue: $" << myMarket.GetRevenue() << endl;
  
}
