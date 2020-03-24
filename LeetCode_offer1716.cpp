/*************************************************************************
	> File Name: LeetCode_offer1716.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Mar 2020 11:24:47 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int massage(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    return dp[nums.size() - 1];
}

int massage(vector<int>& nums) {
    int formorTwo = 0, pre = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int cur = max(formorTwo, pre + nums[i]);
        pre = formorTwo;
        formorTwo = cur;
    }
    return formorTwo;
}
