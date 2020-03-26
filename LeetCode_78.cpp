/*************************************************************************
	> File Name: LeetCode_78.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Mar 2020 08:37:30 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void GetSubset(vector<int>& nums, vector<vector<int>>& result, vector<int>& gather, int index, int subsetsNumber, int curCount)
{
    for (int i = index; i < nums.size() && nums.size() - i >= subsetsNumber - curCount && curCount < subsetsNumber; ++i)
    {
        gather[curCount] = nums[i];
        GetSubset(nums, result, gather, i + 1, subsetsNumber, curCount + 1);
        if (curCount + 1 == subsetsNumber)
            result.push_back(gather);
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); ++i)
    {    
        vector<int> gather(i + 1);
        GetSubset(nums, result, gather, 0, i + 1, 0);
    }
    result.push_back(vector<int>());
    return result;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    vector<vector<int>> result = subsets(nums);
    for (auto x : result)
    {
        for (auto y : x)
            printf("%d ", y);
        printf("\n");
    }
}

void test1()
{
    vector<int> nums{1, 2, 3};
    test("Test1", nums);
}

void test2()
{
    vector<int>
}

int main()
{
    test1();
}
