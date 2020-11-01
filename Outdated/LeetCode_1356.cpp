/*************************************************************************
	> File Name: LeetCode_1356.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Mar 2020 09:35:27 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int countBit(int num)
{
    int count = 0;
    while (num)
    {
        num &= num - 1;
        count++;
    }
    return count;
}
vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [&](int a, int b){
            return countBit(a) == countBit(b) ? a < b : countBit(a) < countBit(b);
    });
    return arr;
}
