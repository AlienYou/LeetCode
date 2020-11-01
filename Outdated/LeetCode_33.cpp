/*************************************************************************
	> File Name: LeetCode_33.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Apr 2020 08:48:39 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return -1;
    int left = 0, right = nums.size() - 1;
    int piv = -1;
    while (left + 1 < right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] > nums[left])
            left = mid;
        else if (nums[mid] < nums[right])
            right = mid;
    }
    if (target <= nums[left] && target >= nums[0])
    {
        right = left;
        left = 0;
    }
    else
    {
        left = right;
        right = nums.size() - 1;
    }
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int search2(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target)
            return mid;
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
