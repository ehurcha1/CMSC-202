#include <iostream>
using namespace std;

const int NUM_NUMBERS = 5;
//#define NUM_NUMBERS 5

int main(){
    int numbers[NUM_NUMBERS];
    int total = 0;
    for(int i  = 0; i <NUM_NUMBERS;i++){
        cin >> numbers[i];
        cout << numbers[i] << endl;
        total += numbers[i];
        
    }
}

// useful things for proj1. dont have to return array, but you can pass them. declare in main, pass them to function, manipulate. "pass by reference"