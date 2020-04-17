/*************************************************************************
	> File Name: LeetCode_55.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Apr 2020 12:31:00 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/ bool Core(vector<int>& nums, int index)
// {
//     if (index >= nums.size() - 1 || nums[index] + index >= nums.size() - 1)
//         return true;
//     for (int i = nums[index]; i > 0; --i)
//     {
//         if (Core(nums, index + i))
//             return true;
//     }
//     return false;
// }
bool canJump(vector<int>& nums) {
    int maxLength = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > maxLength)
            return false;
        if (maxLength >= nums.size() - 1)
            return true;
        maxLength = max(maxLength, i + nums[i]);
    }
    return true;
}
