/*************************************************************************
	> File Name: LeetCode_14.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Mar 2020 07:14:47 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result;
    if (strs.size() == 0)
        return result;
    int minLength = 0xFFFFFFF;
    for (int i = 0; i < strs.size(); ++i)
        if (minLength > strs[i].length())
            minLength = strs[i].length();
    for (int i = 0; i < minLength; ++i)
    {
        int j = 1;
        bool prefix = true;
        for (; j < strs.size(); ++j)
        {
            if (strs[j][i] != strs[j - 1][i])
                return result;
        }
            result += strs[j - 1][i];
    }
    return result;
}
