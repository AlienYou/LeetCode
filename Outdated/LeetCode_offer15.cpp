/*************************************************************************
	> File Name: LeetCode_offer15.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Feb 2020 08:00:07 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int HammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n &= n - 1;
        ++count;
    }
    return count;
}

void test(const char* testName, uint32_t n, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = HammingWeight(n);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", ans);
}

int main()
{
    test("Test1", 11, 3);
}
