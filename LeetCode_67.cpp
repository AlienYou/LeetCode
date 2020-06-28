/*************************************************************************
	> File Name: LeetCode_67.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jun 2020 01:32:31 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addBinary(string a, string b)
{
    int n = max(a.length(), b.length());
    int carryBit = 0;
    string result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        carryBit += i < a.length() && a[i] == '1'? 1 : 0;
        carryBit += i < b.length() && b[i] == '1'? 1 : 0;
        result.push_back(carryBit % 2 == 0 ? '0' : '1');
        carryBit /= 2;
    }
    if (carryBit)
        result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}
