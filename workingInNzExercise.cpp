// workingInNzExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int calculateNthNumberInSequence(int previousNum, int currentNum, int nthNumberCtr)
{
    int total = previousNum + currentNum;
    if (nthNumberCtr == 1)
        return currentNum;
    else
        return calculateNthNumberInSequence(currentNum, total, nthNumberCtr - 1);
}

int main(void)
{
#define TEST1

#ifdef TEST1
    int nthNumberCtr = 15;
    int firstNum = 2;
    int secondNum = 2;
#endif

    if (nthNumberCtr == 1)
        return firstNum;
    else if (nthNumberCtr == 2)
        return firstNum + secondNum;
    else
    {
        int nthNumber = calculateNthNumberInSequence(secondNum, firstNum + secondNum, nthNumberCtr - 2);
        std::cout << "Nth number is: " << nthNumber << std::endl;
        return calculateNthNumberInSequence(secondNum, firstNum + secondNum, nthNumberCtr - 2);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
