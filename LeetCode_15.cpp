/*************************************************************************
	> File Name: LeetCode_15.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Jun 2020 11:49:42 PM PDT
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 0)
        return res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int first = 0; first < size; ++first)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        int third = size - 1;
        int target = -nums[first];
        for (int second = first + 1; second < size; ++second)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            while (second < third && nums[second] + nums[third] > target)
                --third;
            if (second == third)
                break;
            if (nums[second] + nums[third] == target)
                res.push_back({nums[first], nums[second], nums[third]});
        }
    }
    return res;
}
