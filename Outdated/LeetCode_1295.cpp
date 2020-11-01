/*************************************************************************
	> File Name: LeetCode_1295.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Feb 2020 07:31:33 PM PST
 ************************************************************************/
//统计位数为偶数的数字
#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>

using namespace std;

int FindNumbers(vector<int>& nums)
{
    if (nums.size() <= 0)
        return 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (!(to_string(nums[i]).size() & 0x1)) ++count;
    return count;
}
//c++17
int FindNumbers_2(vector<int>& nums)
{
    return accumulate(nums.begin(), nums.end(), 0, [](int result, int x){ return result + !(to_string(x).size() & 0x1); });
}

int FindNumbers_3(vector<int>& nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!((static_cast<int>(log10(nums[i])) + 1) & 0x1))
            ++count;
    }
    return count;
}

void test(const char* testName, vector<int>& nums, int expectedCount)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (FindNumbers_3(nums) == expectedCount)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    int nums[] = {555, 901, 482, 1771};
    vector<int> numsVec(nums, nums + 4);
    test("Test1", numsVec, 1);
}

void test2()
{
    int nums[] = {1};
    vector<int> numsVec(nums, nums + 1);
    test("Test2", numsVec, 0);
}

int main()
{
    test1();
    test2();
}
