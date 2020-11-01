/*************************************************************************
	> File Name: LeetCode_10.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jul 2020 03:38:25 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
bool MatchCore(string &s, int indexS, string &p, int indexP)
{
    if (indexS == s.length() && indexP == p.length())
        return true;
    if (indexS < s.length() && indexP == p.length())
        return false;

    if (indexP + 1 < p.length() && p[indexP + 1] == '*')
    {
        if (indexS < s.length() && (s[indexS] == p[indexP] || p[indexP] == '.'))
        {
            return MatchCore(s, indexS + 1, p, indexP)
                || MatchCore(s, indexS, p, indexP + 2);
        }
        else
            return MatchCore(s, indexS, p, indexP + 2);
    }
    if (indexS < s.length() && (s[indexS] == p[indexP] || p[indexP] == '.'))
    {
        return MatchCore(s, indexS + 1, p, indexP + 1);
    }
    return false;
}
bool isMatch1(string s, string p) {
    return MatchCore(s, 0, p, 0);
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < m + 1; ++i)
    {
        if (p[i - 1] == '*' && i >= 2)
            dp[i][0] = dp[i - 2][0];
    }

    cout << "end" << endl;

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (p[i - 1] == '*')
            {
                if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
                    dp[i][j] = dp[i][j - 1] || dp[i - 2][j];
                else
                    dp[i][j] = dp[i - 2][j];
            }
            else if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    /*for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    return dp[m][n];
}
