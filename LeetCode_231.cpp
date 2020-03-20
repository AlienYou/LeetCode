/*************************************************************************
	> File Name: LeetCode_231.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Mar 2020 08:44:24 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    return !((n - 1) & n);
}
