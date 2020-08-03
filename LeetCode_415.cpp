/*************************************************************************
	> File Name: LeetCode_415.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Aug 2020 08:38:18 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addStrings1(string num1, string num2) {
    string res;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int lengthNum1 = num1.length();
    int lengthNum2 = num2.length();
    int length = max(lengthNum1, lengthNum2);
    bool carrybit = false;
    for (int i = 0; i < length; ++i)
    {
        int sum = 0;
        if (carrybit)
        {
            carrybit = false;
            sum += 1;
        }
        sum += i < lengthNum1? num1[i] - '0' : 0;
        sum += i < lengthNum2? num2[i] - '0' : 0;
        if (sum >= 10)
        {
            sum -= 10;
            carrybit = true;
        }
        res += sum + '0';
    }
    if (carrybit)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

string addStrings(string num1, string num2){
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int add = 0;
    string res = "";
    while (i >= 0 || j >= 0 || add != 0)
    {
        add += i >= 0 ? num1[i] - '0' : 0;
        add += j >= 0 ? num2[j] - '0' : 0;
        res.push_back('0' + add % 10);
        add /= 10;
        --i;
        --j;
    }
    reverse(res.begin(), res.end());
    return res;
}
