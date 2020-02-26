/*************************************************************************
	> File Name: LeetCode_1304.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Feb 2020 08:24:28 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

vector<int> SumZero(int n)
{
    vector<int> ans;
    ans.assign(n, 0);
    int start = n >> 1;
    for (int i = start; i - 1 >= 0; --i)
    {
        ans[i - 1] = i;
        ans[n - i] = -i;
    }

    return ans;
}

void test(const char* testName, int n)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = SumZero(n);
    for (auto &x : result)
        printf("%d ", x);
    printf("\n");
}

int main()
{
    test("Test1", 2);
    test("Test2", 3);
    test("Test3", 4);
    test("Test4", 5);
    test("Test5", 1);
    test("Test6", 0);
}

