/*************************************************************************
	> File Name: LeetCode_287.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 May 2020 05:48:49 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate1(vector<int>& nums) {
    int result = -1;
    for (int i  = 0; i < nums.size();)
    {
        if (i + 1 != nums[i])
        {   
            if (nums[i] == nums[nums[i] - 1])
            {
                result = nums[i];
                break;
            }
            swap(nums[nums[i] - 1], nums[i]);
        }
        else
            ++i;
    }
    return result;
}
int findDuplicate2(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while (nums[slow] != nums[fast]);
    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return nums[slow];
}
int findDuplicate3(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= mid)
                cnt++;
        }
        if (cnt <= mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int bitCount = 31;
    int result = 0;
    while (!((n - 1) >> bitCount))
        bitCount -= 1;
    for (int i = 0; i <= bitCount; ++i)
    {
        int x = 0;
        int y = 0;
        for (int index = 0; index < n; ++index)
        {
            if (nums[index] & (1 << i))
                ++x;
            if (index > 0 && (index & (1 << i)))
                ++y;
        }
        if (x > y)
            result |= (1 << i); 
    }
    return result;
}
