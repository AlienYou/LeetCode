/*************************************************************************
	> File Name: LeetCode_292.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Mar 2020 02:27:29 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool CanWinNim(int n)
{
    vector<bool> dp(n + 1, true);
    for (int i = 4; i <= n; ++i)
        dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
    return dp[n];
}

void test(const char* testName, int n, bool expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (CanWinNim(n) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main()
{
    test("Test1", 4, false);
    test("Test2", 5, true);
    test("Test3", 6, true);
    test("Test4", 7, true);
    test("Test5", 8, false);
}
