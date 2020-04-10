/*************************************************************************
	> File Name: LeetCode_151.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Apr 2020 08:43:04 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverseCore(int left, int right, string& s)
{
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}
string reverseWords(string s) {
    if (s.length() == 0)
        return "";
    int left = 0, right = s.length() - 1;
    while (left <= right && (s[left] == ' ' || s[right] == ' '))
    {
        if (s[left] == ' ') ++left;
        if (s[right] == ' ') --right;
    }
    reverseCore(left, right, s);
    int limit = right;
    right = left;
    string result;
    while (right <= limit)
    {
        if (s[right] == ' ')
        {
            if (s[right + 1] != ' ')
                result += s[right];
        }
        else
            result += s[right];
        ++right;
    }
    left = right = 0;
    while (right < result.length())
    {
        if (result[right] == ' ')
        {
            reverseCore(left, right - 1, result);
            left = right + 1;
        }
        else if (right == result.length() - 1)
            reverseCore(left, right, result);
        ++right;
    }
    return result;
}


string reverseWords2(string s) {
    if (s.length() == 0)
        return "";
    reverse(s.begin(), s.end());
    int length = s.length();
    int pos = 0;
    for (int begin = 0; begin < length; ++begin)
    {
        if (s[begin] != ' ')
        {
            if (pos > 0)
                s[pos++] = ' ';
            int end = begin;
            while (end < length && s[end] != ' ')
                s[pos++] = s[end++];
            reverse(s.begin() + pos - (end - begin), s.begin() + pos);
            begin = end;
        }
    }
    s.erase(s.begin() + pos, s.end());
    return s;
}
