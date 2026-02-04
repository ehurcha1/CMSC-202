#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int num = 5;
    int numNum = 9;
    int numNumNum = num * numNum;
    std::cout << numNumNum;
    std::cout << "\n";
    bool tof;
    if (numNumNum == 45)
        tof = true;
    else
        tof = false;
    std::cout << tof;
    std::cout << "\n";
    return 0;
}