/*************************************************************************
	> File Name: LeetCode_1365.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Mar 2020 01:49:21 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> SmallerNumbersThanCurrent(vector<int>& nums)
{
    vector<int> result;
    vector<int> bucket(101, 0);
    for (int i = 0; i < nums.size(); ++i)
        ++bucket[nums[i]];
    for (int i = 1; i < bucket.size(); ++i)
        bucket[i] += bucket[i - 1];
    for (int i = 0; i < nums.size(); i++)
        if (nums[i]) result.push_back(bucket[nums[i] - 1]);
        else result.push_back(0);
    return result;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> ans = SmallerNumbersThanCurrent(nums);
    for (auto &x : ans)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    int num[] = {8, 1, 2, 2, 3};
    vector<int> numVec(num, num + 5);
    test("Test1", numVec);
}

void test2()
{
    int num[] = {4, 0, 0, 2, 1};
    vector<int> numVec(num, num + 5);
    test("Test2", numVec);
}

int main()
{
    test1();
    test2();
}
