/*************************************************************************
	> File Name: LeetCode_125.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 May 2020 08:48:00 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
bool Judge(string& s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        --end;
    }
    return true;
}
bool validPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            ++start;
            --end;
        }
        else
        {
            return Judge(s, start, end - 1) || Judge(s, start + 1, end);
        }
    }
    return true;
}
