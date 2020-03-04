/*************************************************************************
	> File Name: LeetCode_561.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Mar 2020 03:43:36 AM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int ArrayPairSum(vector<int>& nums)
{
    int bucket[20001] = {0};
    for (int i = 0; i < nums.size(); ++i)
        bucket[nums[i] + 10000]++;
    bool odd = true;
    int sum = 0;
    for (int i = 0; i < 20001; ++i)
    {
        for (int j = 0; j < bucket[i]; ++j)
        {
            if (odd)
                sum += i - 10000;
            odd = !odd;
        }
    }
    return sum;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = ArrayPairSum(nums);
    printf("%d\n", result);
}

void test1()
{
    int num[] = {1, 4, 3, 2};
    vector<int> vec(num, num + 4);
    test("Test1", vec);
}

int main()
{
    test1();
}
