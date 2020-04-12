/*************************************************************************
	> File Name: LeetCode_offer21.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Apr 2020 07:53:23 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> exchange(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums;
    int index = 0;
    int oddIndex = 0;
    int evenIndex = nums.size() - 1;
    while (oddIndex < evenIndex)
    {
        if ((nums[oddIndex] & 0x1) == 0)
        {
            if ((nums[evenIndex] & 0x1) == 1)
            {    
                swap(nums[oddIndex], nums[evenIndex]);
                ++oddIndex;
            }
            --evenIndex;
        }
        else
            ++oddIndex;
    }
    return nums;
}
