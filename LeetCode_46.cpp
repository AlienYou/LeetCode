/*************************************************************************
	> File Name: LeetCode_46.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Apr 2020 09:27:18 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int>& nums, int index, vector<vector<int>>& result)
{
    if (index >= nums.size())
    {
        result.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[index], nums[i]);
        permutations(nums, index + 1, result);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permutations(nums, 0, result);
    return result;
}
