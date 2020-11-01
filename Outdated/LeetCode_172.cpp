/*************************************************************************
	> File Name: LeetCode_172.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Mar 2020 08:39:16 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n)
    {
        count += n / 5;
        n /= 5;
    }
    return count;
}
