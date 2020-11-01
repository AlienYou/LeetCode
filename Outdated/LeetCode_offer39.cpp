/*************************************************************************
	> File Name: LeetCode_offer39.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Mar 2020 12:05:34 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int MajorityElement(vector<int>& nums)
{
    int curNum = nums[0];
    int vote = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (vote == 0) curNum = nums[i];
        if (curNum == nums[i])
            ++vote;
        else
            --vote;
    }
    return curNum;
}
