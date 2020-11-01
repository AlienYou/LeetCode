/*************************************************************************
	> File Name: LeetCode_53.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Mar 2020 11:44:58 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxSum = 0x80000000;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (sum <= 0)
            sum = nums[i];
        else
            sum += nums[i];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
