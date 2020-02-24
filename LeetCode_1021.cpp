/*************************************************************************
	> File Name: LeetCode_1021.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Feb 2020 07:39:18 PM PST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

string RemoveOuterParentheses(string S)
{
    string ans;
    stack<char> outerPareStack;

    for (int i = 0; i < S.length(); i++)
    {
        if (outerPareStack.size() >= 1)
        {
            if (outerPareStack.top() == S[i])
            {
                ans += S[i];
                outerPareStack.push(S[i]);
            }
            else
            {
                if (outerPareStack.size() > 1)
                    ans += S[i];
                outerPareStack.pop();
            }
        }
        else
            outerPareStack.push(S[i]);
    }
    return ans;
}

//LeetCode上别人的解法！主要是通过少算一层括号的方式去掉最外层括号
string RemoveOuterParentheses_2(string S)
{
    string ans;
    stack<char> myStack;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == ')')
            myStack.pop();
        if (!myStack.empty())
            ans += S[i];
        if (S[i] == '(')
            myStack.push(S[i]);
    }
    return ans;
}

void test(const char* testName, string S)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    string ans = RemoveOuterParentheses_2(S);
    printf("%s\n", ans.c_str());
}

int main()
{
    test("Test1", "(()())(())");
    test("Test2", "(()())(())(()(()))");
}
