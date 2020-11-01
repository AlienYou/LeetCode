/*************************************************************************
	> File Name: LeetCode_3.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 May 2020 11:47:06 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int res = 0;
    int hash[128];
    memset(hash, -1, sizeof(hash));
    int left = 0;
    int right = 0;
    int length = s.length();
    while (right < length)
    {
        if (hash[s[right]] >= left)
        {
            res = max(res, right - left);
            left = hash[s[right]] + 1;
        }
        else if (right == length - 1)
        {
            res = max(res, right - left + 1);
        }
        hash[s[right]] = right;
        right++;
    }
    return res;
}

int lengthOfLongestSubstring2(string s)
{
int length = s.length();
    int res = 0;
    int hash[128];
    memset(hash, 0, sizeof(hash));
    for (int i = 0, j = 0; j < length; ++j)
    {
        hash[s[j]]++;
        while (hash[s[j]] > 1)
        {
            hash[s[i++]]--;
        }
        res = max(res, j - i + 1);
    }
    return res;
}
