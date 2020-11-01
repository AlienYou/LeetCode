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

bool isPalindrome_2(int x) {
   if (x < 0 || (x % 10 == 0 && x != 0))
        return false; 
    int reverHalf = 0;
    while (x > reverHalf)
    {
        reverHalf = reverHalf * 10 + x % 10;
        x /= 10;
    }
    return x == reverHalf || (reverHalf / 10 == x) ;
}

bool isPalindrome(int x) {
   if (x < 0)
        return false; 
    if (reverse(x) == x)
        return true;
    return false;
}
