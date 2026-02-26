#include <iostream>
using namespace std;
/*****************************************
 ** File:    lab4.cpp
 ** Project: CMSC 202 Lab 4, Spring 2026
 **
 ** Lab 4 involves passing data to void functions by reference
 ** and by using pointers.
 **
 ***********************************************/

// Function Prototypes (Write for deposit and withdraw)
// ****Write prototypes for deposit and withdraw here****



int main(){
  int balance = 1000; //Starting money in account

  int choice = 0; //Used for menu below
  int amount = 0; //Amount to withdraw or deposit

  cout << "Welcome to the Banking program" << endl;
  do{
    cout << "1. Deposit Cash" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. End Program" << endl;
    cout << "Current Balance " << balance << endl;
    cin >> choice;

    switch (choice){
      case 1:
        cout <<"Enter Amount To Deposit" << endl;
        cin >> amount;
        deposit(amount, balance);
        break;
      case 2:
        cout <<"Enter Amount To Withdraw" << endl;
        cin >> amount;
        withdraw(amount, &balance);
        break;
      case 3:
        break;
      default:
	cout <<"Invalid input" << endl;
    }
  }while (choice != 3);
}

// ****Write deposit function HERE****
// Amount is passed by value and balance is passed by reference
// Validates amount deposited is greater or equal to 0
int deposit(int amount, int &balance){
  if (amount <= 0){
    cout << "Amount cannot be negative." << endl;
    return balance;
  }
  balance += amount;
  return balance;
}


// ****Write withdraw function HERE****
// Amount is passed by value and balance is passed by pointer
// Validates that the amount withdrawn does not exceed account balance
int withdraw(int amount, int *balance){
  if (amount > *balance){
    cout >> "Amount cannot exceed account balance" >> enedl;
    return *balance;
  }
  balance -= amount;
  return *balance;
}