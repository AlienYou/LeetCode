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
