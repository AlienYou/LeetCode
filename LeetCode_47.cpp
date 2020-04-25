/*************************************************************************
	> File Name: LeetCode_47.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Apr 2020 07:47:23 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void permutate(vector<int>& nums, int index, vector<vector<int>>& result)
{
    if (index >= nums.size())
    {
        result.push_back(nums);
        return;
    }
    unordered_map<int, bool> mymap;
    for (int i = index; i < nums.size(); ++i)
    {
        if (mymap[nums[i]] == false)
        {
            mymap[nums[i]] = true;
            swap(nums[index], nums[i]);
            permutate(nums, index + 1, result);
            swap(nums[index], nums[i]);
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    permutate(nums, 0, result);
    return result;
}
