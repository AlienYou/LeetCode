/*************************************************************************
	> File Name: LeetCode_137.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Apr 2020 09:10:45 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
     unordered_map<int, int> count;
     int n = nums.size();
     for (int i = 0; i < n; ++i)
         count[nums[i]]++;
     unordered_map<int, int>::iterator it = count.begin();
     for (; it != count.end(); ++it)
         if (it->second == 1)
             break;
     return it->first;
 }
int singleNumber2(vector<int>& nums) {
    int result = 0;
    int n = nums.size();
    for (int i = 0; i < 32; ++i)
    {
        int bit = 1 << i;
        int cnt = 0; 
        for (int j = 0; j < n; ++j)
        {
            if (nums[j] & bit)
                cnt++;
        }
        if (cnt % 3 != 0)
            result |= bit;
    }
    return result;
}
