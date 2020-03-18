/*************************************************************************
	> File Name: LeetCode_9.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Mar 2020 08:37:00 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
long reverse(int x)
{
    long reInterger = 0;
    while (x)
    {
        reInterger = reInterger * 10 + (x % 10);
        x /= 10;
    }
    return reInterger;
}
bool isPalindrome(int x) {
   if (x < 0)
        return false; 
    if (reverse(x) == x)
        return true;
    return false;
}
