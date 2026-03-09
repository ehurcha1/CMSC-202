/***************************************************************
** Topic: Lab 5
** File: FarmersMarket.h
** Description: This file contains the FarmersMarket class declaration
***************************************************************/

#ifndef FARMERS_MARKET_H //Header Guards
#define FARMERS_MARKET_H //Header Guards

#include <iostream>
#include <iomanip>
using namespace std;

// Declare the FarmersMarket class here
// The default constructor is provided, as are examples of getters
// and setters. You will need to implement the remaining
// getters and setters for all member variables,
// and the functions described in the lab document

class FarmersMarket {
public:
  // Default constructor for FarmersMarket (implementation provided)
  FarmersMarket();


  // Getters
  // Getter for Corn Available (implementation provided)
  int GetCornCount() const;

  // Getter for Carrot Available
  int GetCarrotCount() const;

  // Getter for Corn Price
  float GetCornPrice() const;

  // Getter for Carrot Price
  float GetCarrotPrice() const;\

  // Getter for Revenue
  float GetRevenue() const;


  // Setters
  // Sets Number of Corn Available (implementation provided)
  void SetCornCount(int corn);

  // Sets Number of Carrots Available
  void SetCarrotCount(int carrot);

  // Sets Corn Price
  void SetCornPrice(float price);

  // Sets Carrot Price
  void SetCarrotPrice(float price);
  
  // Sets Total Revenue
  void SetRevenue(float revenue);


  // Other
  // Sell Corn
  void SellCorn();

  // Sell a Carrot
  void SellCarrot();

  // Sell All (implementation provided)
  void SellAll();
  
// Declare five member variables
// (corn count, carrot count, corn price, carrot price, revenue)
// Hint: You can get the correct names from the FarmersMarket.cpp
//      file or lab doc
private:
  int m_corn;
  int m_carrot;
  float m_cornPrice;
  float m_carrotPrice;
  float m_revenue;

};

#endif //End of Header Guards
