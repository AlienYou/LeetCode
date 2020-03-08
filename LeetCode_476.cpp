/*************************************************************************
	> File Name: LeetCode_476.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Mar 2020 06:03:13 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int FindComplement(int num)
{
    unsigned int bitMask = 0x80000000;
    bool firstNonZeroBit = false;
    while (bitMask)
    {
        bitMask >>= 1;
        if (!firstNonZeroBit && (bitMask & num))
            firstNonZeroBit = true;
        if (firstNonZeroBit)
            num ^= bitMask;
    }
    return num;
}

int FindComplement_2(int num)
{
    unsigned int bit = 0x1;
    int result = num;
    while (bit <= num)
    {
        result ^= bit;
        bit <<= 1;
    }
    return result;
}

int FindComplement_3(int num)
{
    unsigned int n = 1;
    while (n < num)
        n = (n << 1) + 1;
    return n ^ num;
}

void test(const char* testName, int num)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    printf("%d\n", FindComplement(num));
    printf("%d\n", FindComplement_2(num));
    printf("%d\n", FindComplement_3(num));
}

int main()
{
    test("Test1", 5);
}
