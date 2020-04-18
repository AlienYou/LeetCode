/*************************************************************************
	> File Name: LeetCode_279.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Apr 2020 04:42:49 AM PDT
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;
int numSquares(int n) {
    unique_ptr<int[]> dp(new int[n + 1]());
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 3;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 2; i * i <= n; ++i)
    {    
        if (i * i == n)
            return 1;
        dp[i * i] = 1;
    }
    for (int i = 5; i <= n; ++i)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            if (dp[i])
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            else
                dp[i] = dp[i - j * j] + 1;
        }
    }
    return dp[n];
}

int numSquares(int n) {
    unique_ptr<int[]> dp(new int[n + 1]());
    for (int i = 1; i <= n; ++i)
    {
        int minVal = numeric_limits<int>::max();
        for (int j = 1; j * j <= i; ++j)
        {
            minVal = min(minVal, dp[i - j * j]);
        }
        dp[i] = minVal + 1;
    }
    return dp[n];
}
