/*************************************************************************
	> File Name: LeetCode_72.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Apr 2020 12:12:30 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = i;
    for (int i = 0; i < m + 1; i++)
        dp[0][i] = i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (word1[i] == word2[j])
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else
                dp[i + 1][j + 1] = min(min(dp[i][j], dp[i][j + 1]), dp[i + 1][j]) + 1;
        }
    }
    return dp[n][m];
}
