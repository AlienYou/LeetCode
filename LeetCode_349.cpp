/*************************************************************************
	> File Name: LeetCode_349.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Mar 2020 11:09:31 PM PST
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;

vector<int> Intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, bool> mymap;
    vector<int> result;
    for (int i = 0; i < nums1.size(); ++i)
        mymap.insert(pair<int, bool>(nums1[i], true));
    for (int i = 0; i < nums2.size(); ++i)
    {
        if (mymap[nums2[i]] == true)
        {
            mymap[nums2[i]] = false;
            result.push_back(nums2[i]);
        }
    }
    return result;
}

void test(const char* testName, vector<int>& nums1, vector<int>& nums2)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = Intersection(nums1, nums2);
    for (auto &x : result)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    vector<int> vec1(nums1, nums1 + 4);
    vector<int> vec2(nums2, nums2 + 2);

    test("Test1", vec1, vec2);
}

void test2()
{
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};
    vector<int> vec1(nums1, nums1 + 3);
    vector<int> vec2(nums2, nums2 + 5);
    test("Test2", vec1, vec2);
}

int main()
{
    test1();
    test2();
}
