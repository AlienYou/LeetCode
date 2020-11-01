/*************************************************************************
	> File Name: LeetCode_offer57.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Mar 2020 10:39:45 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> FindContinuousSequence(int target)
{
    vector<vector<int>> result;
    if (target <= 2)
        return result;
    int limit = (target + 1) >> 1;

    int start = 1;
    int end = 2;
    int sum = start + end;
    while (start < end && end <= limit)
    {
        if (sum < target)
        {   
            ++end;
            sum += end;
        }
        else if (sum > target)
        {   
            sum -= start;
            ++start;
        }
        else
        {
            vector<int> find;
            for (int i = start; i <= end; ++i)
                find.push_back(i);
            result.push_back(find);
            ++end;
            sum += end;
        }
    }
    return result;
}

void test(const char* testName, int target)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    vector<vector<int>> result = FindContinuousSequence(target);
    for (auto x : result)
    {
        for(auto y : x)
            printf("%d ", y);
        printf("\n");
    }
}

int main()
{
    test("Test1", 15);
}
