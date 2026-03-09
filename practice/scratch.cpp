#include <iostream>
using namespace std;

void swap(int *ptrA, int *ptrB);

int main(){
    int a = 5;
    int b = 10;
    swap(&a, &b);

    return 0;
}

void swap(int *ptrA, int *ptrB){
    int valueHolderA = 0;
    int valueHolderB = 0;
    
    valueHolderB = *ptrB;
    valueHolderA = *ptrA;
    
    *ptrA = valueHolderB;
    *ptrB = valueHolderA;

}