/*************************************************************************
	> File Name: LeetCode_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Apr 2020 12:38:51 AM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return {};
    unordered_map<int, int> mymap;
    for (int i = 0; i < nums.size(); ++i)
    { 
        int f = target - nums[i];
        unordered_map<int, int>::iterator mit = mymap.find(f);
        if (mit != mymap.end())
            return {mit->second, i};
        mymap.insert(make_pair(nums[i], i));            
    }
    
    return {};
}
