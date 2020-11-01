/*************************************************************************
	> File Name: LeetCode_44.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jul 2020 12:11:15 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < m + 1; ++i)
    {
        if (p[i - 1] == '*')
            dp[i][0] = true;
        else
            break;
    } 
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    /*for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    return dp[m][n];
}
