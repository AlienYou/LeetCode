/*************************************************************************
	> File Name: LeetCode_198.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 May 2020 06:47:25 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int rob(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int preRob = nums[0];
    int curRob = max(preRob, nums[1]);
    for (int i = 2; i < nums.size(); ++i)
    {
        int temp = curRob;
        curRob = max(curRob, preRob + nums[i]);
        preRob = temp;
    }
    return curRob;
}
