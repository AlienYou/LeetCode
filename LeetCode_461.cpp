/*************************************************************************
	> File Name: LeetCode_461.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Feb 2020 06:36:21 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int HammingDistance(int x, int y)
{
    int count = 0;
    int diff = x ^ y;
    unsigned int bit = 0x1;
    while (bit)
    {
        if (diff & bit)
            count++;
        bit <<= 1;
    }

    return count;
}
int HammingDistance_2(int x, int y)
{
    int diff = x ^ y;
    int count = 0;
    while (diff)
    {
        diff &= diff - 1;
        ++count;
    }
    return count;
}

void test(const char* testName, int x, int y, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = HammingDistance_2(x, y);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", ans);
}

int main()
{
    test("Test1", 1, 4, 2);
}
