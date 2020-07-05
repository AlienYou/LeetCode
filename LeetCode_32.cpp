/*************************************************************************
	> File Name: LeetCode_32.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jul 2020 01:18:35 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int longestValidParentheses1(string s) {
    int result = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.empty())
                st.push(i);
            else 
            {
                result = max(result, i - st.top());
            }
        }
    }
    return result;
}
int longestValidParentheses(string s) { 
    if (s.length() == 0)
        return 0;
    vector<int> dp(s.length(), 0);
    int result = 0;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            else
            {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                    else
                        dp[i] = dp[i - 1] + 2;
                }
            }
            result = max(dp[i], result);
        }
    }
    return result;
} 
