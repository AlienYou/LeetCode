/*************************************************************************
	> File Name: LeetCode_50.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Apr 2020 07:27:44 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
double Power(double base, unsigned int n)
{
    if (n == 1)
        return base;
    double result = Power(base, n >> 1);
    result *= result;
    if (n & 0x1 == 1)
        result *= base;
    return result;
}

double myPow(double x, int n) {
    if (n == 0)
        return 1;
    if (x > 10e-6 && x < -10e-6)
        return 0;
    unsigned int exp = abs(n);
    double result = Power(x, exp);
    if (n < 0)
        result = 1 / result;
    return result;
}
