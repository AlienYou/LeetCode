/*************************************************************************
	> File Name: LeetCode_300.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Mar 2020 07:35:47 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int LengthOfLIS(vector<int>& nums)
{
    int longest = 0;
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(dp[i], longest);
    }
    return longest;
}

int LengthOfLIS_2(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int tail = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > dp[tail])
            dp[++tail] = nums[i];
        else
        {
            int start = 0, end = tail;
            while (start < end)
            {
                int mid = start + ((end - start) >> 1);
                if (dp[mid] > nums[i])
                    end = mid;
                else if (dp[mid] < nums[i])
                    start = mid + 1;
                else
                {
                    start = mid;
                    break;
                }
            }
            dp[start] = nums[i];
        }
    }
    return tail + 1;
}

void test(const char* testName, vector<int>& nums)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = LengthOfLIS_2(nums);
    printf("%d\n", result);
}

void test1()
{
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> vec(nums, nums + 8);
    test("Test1", vec);
}

void test2()
{
    int nums[] = {10, 9, 2, 6, 3, 4, 7, 101, 18};
    vector<int> vec(nums, nums + 9);
    test("Test2", vec);
}

int main()
{
    test1();
    test2();
}
