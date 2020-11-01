/*************************************************************************
	> File Name: LeetCode_16.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jun 2020 10:12:11 PM PDT
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int diff = 10000;
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int start = i + 1;
        int end = size - 1;
        while (start < end)
        {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == target)
                return sum;
            else
            {
                if (abs(sum - target) < diff)
                {
                    result = sum;
                    diff = abs(sum - target);
                }
                if (sum > target)
                {   
                    int endTemp = end - 1;
                    while (start < endTemp && nums[endTemp] == nums[endTemp + 1])
                        --endTemp;
                    end = endTemp;
                }
                else 
                { 
                    int startTemp = start + 1;
                    while (startTemp < end && nums[startTemp] == nums[startTemp - 1])
                        ++startTemp;
                    start = startTemp;
                }
            }
        }
    }
    return result;
}
