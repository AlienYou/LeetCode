/*************************************************************************
	> File Name: LeetCode_645_ErrorSet.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2020 01:25:50 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int g_ResultAnswer = 2;

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> hashVec;
    if (nums.size() < 2)
        return hashVec;
    int length = nums.size();
    hashVec.assign(length + 1, 0);
    
    for (int i = 0; i < length; i++)
        hashVec[nums[i]]++;

    vector<int> result;
    result.assign(2, 0);
    for (int i = 0; i < length + 1; i++)
    {
        if (hashVec[i] == 0 || hashVec[i] == 2)
            result[!hashVec[i]] = i;
    }
    return result;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = findErrorNums(nums);
    for (int i = 0; i < g_ResultAnswer; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void test1()
{
    int nums[] = {1, 2, 2, 4};
    vector<int> numsVec(nums, nums + 4);
    test("Test1", numsVec);
}

void test2()
{
    int nums[] = {2, 4, 5, 3, 2};
    vector<int> numsVec(nums, nums + 5);
    test("Test2", numsVec);
}

void test3()
{
    int nums[] = {2, 3, 1, 2};
    vector<int> numsVec(nums, nums + 4);
    test("Test3", numsVec);
}
int main()
{
    test1();    
    test2();
    test3();
}
