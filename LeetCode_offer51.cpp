/*************************************************************************
	> File Name: LeetCode_offer51.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Apr 2020 05:32:53 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int MergeCore(vector<int>& nums, int left, int right, vector<int>& temp)
{
    if (left >= right)
        return 0;
    int mid = ((right - left) >> 1) + left;
    int ans = MergeCore(nums, left, mid, temp) + MergeCore(nums, mid + 1, right, temp);
    int count = 0, L = mid, R = right;
    int index = right;
    while (L >= left && mid + 1 <= R)
    {
        if (nums[L] > nums[R])
        {
            count += R - mid;
            temp[index--] = nums[L--];
        }
        else
        {
            temp[index--] = nums[R--];
        }
    }
    while (mid + 1 <= R)
        temp[index--] = nums[R--];
    while (L >= left)
        temp[index--] = nums[L--];
    for (int i = left; i <= right; ++i)
        nums[i] = temp[i];
    return count + ans;
}  
int reversePairs(vector<int>& nums) {
    if (nums.size() <= 1)
        return 0;
    vector<int> temp(nums.size());
    return MergeCore(nums, 0, nums.size() - 1, temp);
}
