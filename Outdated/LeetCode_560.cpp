/*************************************************************************
	> File Name: LeetCode_560.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Apr 2020 08:54:31 AM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    if (nums.size() == 0)
        return 0;
    unordered_map<int, int> sumMap;
    sumMap[0] = 1;
    int sum = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        result += sumMap[sum - k];
        sumMap[sum]++;
    }
    return result;
}
