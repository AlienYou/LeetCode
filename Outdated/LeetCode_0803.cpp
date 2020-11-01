/*************************************************************************
	> File Name: LeetCode_0803.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Mar 2020 11:37:16 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int FindCore(vector<int>& nums, int start, int end)
{
    if (start > end)
        return -1;
    int mid = start + ((end - start) >> 1);
    int find = -1;
    if (nums[mid] == mid)
        find = mid;
    else
        find = FindCore(nums, mid + 1, end);
    int findLeft = FindCore(nums, start, mid - 1);
    //if (find == -1 && findLeft != -1 || (find != -1 && findLeft != -1))
    if (findLeft != -1)
        find = findLeft;
    return find;
}

int FindMagicIndex_Recursively(vector<int>& nums)
{
    return FindCore(nums, 0, nums.size() - 1);
}
/*
int FindMagicIndex(vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int findLeft = -1;
    int findRight = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if ()
    }
}*/

void test(const char* testName, vector<int> nums, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = FindMagicIndex_Recursively(nums);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", result);
}

void test1()
{
    int nums[] = {0, 2, 3, 4, 5};
    vector<int> v(nums, nums + 5);
    test("Test1", v, 0);
}

void test2()
{
    int nums[] = {0, 0, 2};
    vector<int> v(nums, nums + 3);
    test("Test2", v, 0);
}

void test3()
{
    int nums[] = {0, 2, 2, 3, 4};
    vector<int> v(nums, nums + 5);
    test("Test3", v, 0);
}

void test4()
{
    int nums[] = {-2, -1, 0, 4, 4};
    vector<int> v(nums, nums + 5);
    test("Test4", v, 4);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
