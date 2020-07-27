/*************************************************************************
	> File Name: LeetCode_392.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jul 2020 11:04:32 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence1(string s, string t) {
    if (s.length() == 0)
        return true;
    int sLength = s.length();
    int tLength = t.length();

    vector<vector<bool>> dp(sLength + 1,  vector<bool>(tLength + 1, false));
    for (int i = 0; i <= tLength; ++i)
        dp[0][i] = true;

    for (int i = 1; i <= sLength; ++i)
    {
        for (int j = 1; j <= tLength; ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[sLength][tLength];
}
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    int sL = s.length();
    int tL = t.length();
    while (i < sL && j < tL)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return i == sL;
}
