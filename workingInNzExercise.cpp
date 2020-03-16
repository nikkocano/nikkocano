#include <iostream>

int calculateNthNumberInSequenceRecur(int nthNumberCtr)
{
    if (nthNumberCtr == 1 || nthNumberCtr == 2)
    {
        return 2;
    }
    else
    {
        return calculateNthNumberInSequenceRecur(nthNumberCtr - 2) +
            calculateNthNumberInSequenceRecur(nthNumberCtr - 1);
    }
}

int calculateNthNumberInSequence(int previousNum, int currentNum, int nthNumberCtr)
{
    for (; nthNumberCtr > 0; --nthNumberCtr)
    {
        int temp = previousNum + currentNum;
        previousNum = currentNum;
        currentNum = temp;
    }
    return previousNum;
}

int main(void)
{
#define TEST1

#ifdef TEST1
    int nthNumberCtr = 15;
    int firstNum = 2;
    int secondNum = 2;
#endif

    int sumOfPreviousAndCurrentNum = firstNum + secondNum;
    if (nthNumberCtr == 1)
        return firstNum;
    else if (nthNumberCtr == 2)
        return sumOfPreviousAndCurrentNum;
    else
    {
        std::cout << "Nth number is: " << calculateNthNumberInSequence(secondNum, sumOfPreviousAndCurrentNum, nthNumberCtr - 2) << std::endl;
        std::cout << "(Recursive) Nth number is: " << calculateNthNumberInSequenceRecur(nthNumberCtr) << std::endl;
    }
}

/*
-What is the 15th element of the sequent ?
    1220
-What is your solution time and space complexity, regarding for the n(th) element of the sequent ?
    O(N)
-What clean code principles you have been used, and why ?
    Keeping it simple, because answer can be achieved in a simple for loop.
    Readability, it is better to understand code as it is rather than relying on to some comment blocks.
    Single Responsibility/Modularity, specify only what a method or function is actually doing.
-Bonus : can you make your code recursive ? If yes, what would be your timeand space complexity ?
    Recursive code is commented-out. I believe it is still linear so the complexity is O(N).

    Edit:
    Since new recursion implementation involves halving the set, time complexity is logarithmic therefore O(2^n).
*/
