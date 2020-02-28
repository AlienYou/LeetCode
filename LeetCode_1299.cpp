/*************************************************************************
	> File Name: LeetCode_1299.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 09:35:44 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

vector<int> ReplaceElements(vector<int>& arr)
{
    int max = -1;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        int temp = arr[i];
        arr[i] = max;
        if (temp > max)
            max = temp;
    }
    return arr;
}

void test(const char* testName, vector<int>& arr)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    ReplaceElements(arr);
    for (auto x : arr)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    int num[] = {17, 18, 5, 4, 6, 1};
    vector<int> numVec(num, num + 6);
    test("Test1", numVec);
}

int main()
{
    test1();
}
