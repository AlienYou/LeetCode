/*************************************************************************
	> File Name: LeetCode_394.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 May 2020 05:34:39 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


string decodeCore(int& curIndex, int depth, int size, string& s)
{
    string ans;
    string curString;
    int times = 0;
    int bracketCounts = 0;
    while (curIndex < size)
    {
        if (s[curIndex] >= '0' && s[curIndex] <= '9')
        {
            if (!bracketCounts)
                times = times * 10 + (s[curIndex] - '0');
            else
                curString += decodeCore(curIndex, depth + 1, size, s);
        }
        else if (s[curIndex] == '[')
            bracketCounts++;
        else if (s[curIndex] == ']')
        {
            bracketCounts--;
            for (int i = 0; i < times; ++i)
                ans += curString;
            if (depth)
                return ans;
            curString.clear();
            times = 0;
        }
        else
        {
            if (bracketCounts)
                curString += s[curIndex];
            else
                ans += s[curIndex];
        }
        ++curIndex;
    }
    return ans;
}
string decodeString1(string s) {
    int curIndex = 0;
    return decodeCore(curIndex, 0, s.length(), s);
}
string getDigits(string& s, size_t& pos)
{
    string digit;
    while (isdigit(s[pos]))
        digit += s[pos++];
    return digit;
}
string getString(vector<string>& v)
{
    string ans = "";
    for (auto &s : v)
        ans += s;
    return ans;
}
string decodeString(string s) {
    vector<string> stc;
    size_t pos = 0;
    int length = s.length();
    while (pos < length)
    {
        char ch = s[pos];
        if (isdigit(ch))
        {
            string digits = getDigits(s, pos);
            stc.push_back(digits);
        }
        else if (isalpha(ch) || ch == '[')
            stc.push_back(string(1, s[pos++]));
        else
        {
            vector<string> s;
            while (stc.back() != "[")
            {
                s.push_back(stc.back());
                stc.pop_back();
            }
            reverse(s.begin(), s.end());
            stc.pop_back();
            int times = stoi(stc.back());
            stc.pop_back();
            string temp, o = getString(s);
            while (times--) temp += o;
            stc.push_back(temp);
            pos++;
        }
    }
    return getString(stc);
}
