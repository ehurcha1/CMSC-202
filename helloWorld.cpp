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
    if (numNumNum == 45) {
        tof = true;
        std::cout << "true\n";
    } else {
        tof = false;
        std::cout << "false\n";
    }    
    return 0;
}