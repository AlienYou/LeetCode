/*************************************************************************
	> File Name: LeetCode_718.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Jul 2020 10:46:17 AM PDT
 ************************************************************************/

#include<vector>
#include<iostream>
using namespace std;
int findLength1(vector<int>& A, vector<int>& B) {
    int result = 0;
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    for (int i = 1; i <= A.size(); ++i)
    {
        for (int j = 1; j <= B.size(); ++j)
        {
            dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
            result = max(dp[i][j], result);
        }
    } 
    return result;
}
int findLength(vector<int>& A, vector<int>& B) {
    int result = 0;
    vector<int> dp(B.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = B.size() - 1; j >= 0; --j)
        {
            dp[j + 1] = A[i] == B[j] ? dp[j] + 1 : 0;
            result = max(result, dp[j + 1]);
        }
    }
    return result;
}
