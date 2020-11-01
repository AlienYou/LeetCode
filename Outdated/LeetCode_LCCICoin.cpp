/*************************************************************************
	> File Name: LeetCode_LCCICoin.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Apr 2020 11:23:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int waysToChange(int n) {
    if (n == 0)
        return 0;
    vector<int> dp(n + 1, 0);
    int coin[4] = {1, 5, 10, 25};
    dp[0] = 1;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (j - coin[i] >= 0)
                dp[j] = (dp[j] + dp[j - coin[i]]) % 1000000007;
    }
    return dp[n];
}
