/*************************************************************************
	> File Name: LeetCode_1342_OperandOfBecomeZero.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2020 05:51:42 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int NumberOfSteps(int num)
{
    if (num < 0)
        return 0;
    int count = 0;
    while (num != 0)
    {
        (num & 0x1) ? num ^= 1 : num >>= 1;
        ++count;
    }
    return count;
}

void test(const char* testName, int num)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    printf("%d\n", NumberOfSteps(num));
}

int main()
{
    test("Test1", 14);
}
