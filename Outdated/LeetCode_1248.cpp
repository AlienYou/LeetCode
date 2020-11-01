/*************************************************************************
	> File Name: LeetCode_1248.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Apr 2020 07:02:16 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int numberOfSubarrays(vector<int>& nums, int k) {
    if (nums.size() == 0)
        return 0;
    int left = 0, right = 0; 
    int count = 0;
    int result = 0;
    while (right < nums.size())
    {
        if (nums[right++] & 1)
            ++count;
        if (count >= k)
        {
            int rightOddCnt = 0;
            int leftOddCnt = 0;
            int r = right;
            while (r < nums.size() && !(nums[r] & 1))
            {
                ++rightOddCnt;
                ++r;
            }
            while (!(nums[left] & 1))
            {
                ++leftOddCnt;
                ++left;
            }
            result += (leftOddCnt + 1) * (rightOddCnt + 1);
            count--;
            left++;
        }
    }
    return result;
}

int numberOfSubarrays2(vector<int>& nums, int k) {
    if (nums.size() == 0)
        return 0;
    vector<int> pre(nums.size() + 1, 0);
    pre[0] = 1;
    int odd = 0, result = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        odd += nums[i] & 1;
        result += odd >= k ? pre[odd - k] : 0;
        pre[odd] += 1;
    }
    return result;
}

int numberOfSubarrays3(vector<int>& nums, int k) {
    if (nums.size() == 0)
        return 0;
    vector<int> hash;
    hash.push_back(-1);
    for(int i = 0; i <= nums.size(); ++i)
        if (i == nums.size() || nums[i] & 1)
            hash.push_back(i);
    int result = 0;
    int size = hash.size();
    for (int i = 1; i + k < size; ++i)
            result += (hash[i] - hash[i - 1]) * (hash[i + k] - hash[i + k - 1]);
    return result;
}
