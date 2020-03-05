/*************************************************************************
	> File Name: LeetCode_1607.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Mar 2020 12:06:33 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int Maximum(int a, int b)
{
    int k = (((long)a - (long)b) >> 63) & 1;
    return b * k + a * (k ^ 1);
}

void test(const char* testName, int a, int b, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = Maximum(a, b);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", ans);
}

int main()
{
    test("Test1", 1, 2, 2);
    test("Test2", 2, 88, 88);
    test("Test3", -1, -2, -1);
    test("Test4", -1, 0x80000000, -1);
    test("Test5", 1, -10, 1);
    test("Test6", 1, 1, 1);
}
