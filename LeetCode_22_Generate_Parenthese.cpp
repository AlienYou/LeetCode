/*************************************************************************
	> File Name: LeetCode_22_Generate_Parenthese.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Apr 2020 11:21:05 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
//暴力求解法，虽然不是优解，但是其中的编码技巧可以学习
bool Valid(string s)
{
    int balance = 0;
    for (char c : s)
    {
        if (c == '(')
            ++balance;
        else
        {
            --balance;
            if (balance < 0)
                return false;
        }
    }
    return balance == 0;
}

void DFS(vector<string>& result, int n, string curString)
{
    if (n == curString.length())
    {
        if (Valid(curString))
            result.push_back(curString);
        return;
    }
    curString += '(';
    DFS(result, n, curString);
    curString.pop_back();

    curString += ')';
    DFS(result, n, curString);
    curString.pop_back();
}
///暴力求解法，虽然不是优解，但是其中的编码技巧可以学习

void DFS2(vector<string>& result, int left, int right, string&& curString)
{
    if (left == 0 && right == 0)
    {
        result.push_back(curString);
        return;
    }
    if (left > right)
        return;
    if (left > 0)
    {
        DFS2(result, left - 1, right, curString + '(');
    }
    if (right > 0)
    {
        DFS2(result, left, right - 1, curString + ')');
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n == 0)
        return result;
    string curString;
    DFS(result, n * 2, curString);
    return result;
}
