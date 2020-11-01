/*************************************************************************
	> File Name: LeetCode_1051.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Feb 2020 08:00:08 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int HeightChecker(vector<int>& heights)
{
    int heightMap[101] = {0};
    for (auto i : heights)
        ++heightMap[i];

    int count = 0;
    int j = 0;
    for (int i = 1; i < 101; ++i)
    {
        while (heightMap[i]-- > 0)
        {
            if (i != heights[j])
                ++count;
            ++j;
        }
    }
    return count;
}

void test(const char* testName, vector<int>& heights, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = HeightChecker(heights);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", result);
}

void test1()
{
    int nums[] = {1, 1, 4, 2, 1, 3};
    vector<int> heights(nums, nums + 6);
    test("Test1", heights, 3);
}

int main()
{
    test1();
}
