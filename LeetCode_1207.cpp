/*************************************************************************
	> File Name: LeetCode_1207.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Mar 2020 07:34:33 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr)
{
    if (arr.size() == 0)
        return false;
    unordered_map<int, int> countMap;
    set<int> countSet;
    for (int i = 0; i < arr.size(); ++i)
        countMap[arr[i]]++;
    for (auto& it : countMap)
        countSet.insert(it.second);
    return countSet.size() == countMap.size();
}

void test(const char* testName, vector<int>& arr, bool expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (uniqueOccurrences(arr) == expected)
        printf("Passed\n");
    else
        printf("Failed.\n");
}

void test1()
{
    int nums[] = {1, 2, 2, 1, 1, 3};
    vector<int> vecs(nums, nums + 6);
    test("Test1", vecs, true);
}
void test2()
{
    int nums[] = {1, 2};
    vector<int> vecs(nums, nums + 2);
    test("Test2", vecs, false);
}

int main()
{
    test1();
    test2();
}
