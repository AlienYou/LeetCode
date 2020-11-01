/*************************************************************************
	> File Name: LeetCode_offer56I.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Apr 2020 09:36:12 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums;
    int bitMask = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
        bitMask ^= nums[i];
    int bitFilt = bitMask & (-bitMask);
    int bitSame = bitMask;
    for (int i = 0; i < n; ++i)
        if (bitFilt & nums[i])
            bitSame ^= nums[i];
    return {bitSame, bitMask ^ bitSame};
}
