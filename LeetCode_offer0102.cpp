/*************************************************************************
	> File Name: LeetCode_offer0102.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Mar 2020 07:47:53 PM PST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

bool CheckPermutation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int sum = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        sum += s1[i];
        sum -= s2[i];
    }
    return (sum == 0);
}

