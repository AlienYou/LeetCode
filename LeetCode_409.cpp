/*************************************************************************
	> File Name: LeetCode_409.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2020 07:08:27 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

 int longestPalindrome(string s) {
    int ascMap[128] = {0};
    for (int i = 0; i < s.length(); ++i)
        ascMap[s[i]]++;
    int result = 0;
    for (int i = 0; i < 128; ++i)
    {
        result += ascMap[i] - (ascMap[i] & 1);
    }
    return result < s.length() ? result + 1 : result;
}

int longestPalindrome_2(string s) {
    int ascMap[128] = {0};
    for (int i = 0; i < s.length(); ++i)
        ascMap[s[i]]++;
    int oddNum = 0;
    for (int i = 0; i < 128; ++i)
    {
        oddNum += (ascMap[i] & 1);
    }
    return oddNum == 0 ? s.length() : (s.length() - oddNum + 1);
}
