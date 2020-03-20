/*************************************************************************
	> File Name: LeetCode_offer40.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Mar 2020 02:36:57 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int RandomIndex(int start, int end)
{
    return start + random() % (end - start + 1);
}

int Core(vector<int>& nums, int start, int end)
{
    int index = RandomIndex(start, end);
    swap(nums[index], nums[end]);
    int small = start;
    for (int i = start; i < end; ++i)
    {
        if (nums[i] < nums[end])
        {
            if (small != i)
                swap(nums[i], nums[small]);
            small++;
        }
    }
    swap(nums[small], nums[end]);
    return small;
}

void QuickSort(vector<int>& nums, int start, int end)
{
    if (start < end)
    {
        int key = Core(nums, start, end);
        QuickSort(nums, start, key - 1);
        QuickSort(nums, key + 1, end);
    }
}

void KthNumbers(vector<int>& arr, int start, int end, int k)
{
    if (start >= end)
        return;
    int index = Core(arr, start, end);
    if (k == index + 1)
        return ;
    else if (k < index + 1)
        KthNumbers(arr, start, index - 1, k);
    else 
        KthNumbers(arr, index + 1, end, k);
}

vector<int> GetLeastNumbers(vector<int>& arr, int k)
{
    vector<int> result;
    if (arr.size() == 0 || k > arr.size() || k <= 0)
        return result;
    result.assign(k, 0);
    KthNumbers(arr, 0, arr.size() - 1, k);
    for (int i = 0; i < k; ++i)
        result[i] = arr[i];
    return result;
}

void test(const char* testName, vector<int>& nums, int k)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = GetLeastNumbers(nums, k);
    for (auto& x : result)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    vector<int> nums = {2, 2, 3, 1, 0, 6, 5};
    test("Test1", nums, 3);
}

void test2()
{
    vector<int> nums = {2};
    test("Test2", nums, 1);
}

int main()
{
    srand(time(0));
    test1();
    test2();
}
