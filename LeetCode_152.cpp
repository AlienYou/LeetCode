/*************************************************************************
	> File Name: LeetCode_152.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 May 2020 07:39:24 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    int res = nums[0];
    int minP = 1;
    int maxP = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        int maxTemp = maxP, minTemp = minP; 
        maxP = max(nums[i] * maxP, max(minTemp * nums[i], nums[i]));
        minP = min(nums[i] * minP, min(maxTemp * nums[i], nums[i]));
        res = max(maxP, res);
    }
    return res;
}
