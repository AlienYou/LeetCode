/*************************************************************************
	> File Name: LeetCode_8.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Apr 2020 11:54:47 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<limits>
using namespace std;
bool CheckIsNumberAndSign(char c)
{
    if (c == '-' || c == '+' || (c >= '0' && c <= '9'))
        return true;
    return false;
}
int myAtoi(string str) {
    if (str.length() == 0)
        return 0;
    int index = 0;  
    while (str[index] == ' ')
    {
        ++index;
    }
    if (!CheckIsNumberAndSign(str[index]))
        return 0;
    int minus = 1;
    if (str[index] == '-')
    {    
        minus = -1;
        ++index;
    }
    else if (str[index] == '+')
        ++index;
    int result = 0;
    while (str[index] >= '0' && str[index] <= '9')
    {
        int digit = str[index] - '0';
        if (result > numeric_limits<int>::max() / 10 || (result == numeric_limits<int>::max() / 10 && digit > 7))
            return minus > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
        result = result * 10 + digit;
        ++index;
    }
    return result * minus;
}
