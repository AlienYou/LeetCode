/*************************************************************************
	> File Name: LeetCode_215.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jun 2020 08:57:21 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int GetIndex(int start, int end)
{
    return rand() % (end - start + 1) + start;
}
int Sort(vector<int>& nums, int start, int end)
{
    int index = GetIndex(start, end);
    swap(nums[index], nums[end]);
    int small = start;
    for (int i = start; i <= end; ++i)
    {
        if (nums[i] > nums[end])
        {
            if (i != small)
            {
                swap(nums[i], nums[small]);
            }
            ++small;
        }
    }
    swap(nums[small], nums[end]);
    return small;
}
int findKthLargest1(vector<int>& nums, int k) {
    srand(time(0));
    int start = 0;
    int end = nums.size() - 1;
    int index = Sort(nums, start, end);
    while (index + 1 != k)
    {
        if (index + 1 > k)
            end = index - 1;
        else
            start = index + 1;
        index = Sort(nums, start, end);
    }
    return nums[index];
}
void Heapify(vector<int>& nums, int index, int heapSize)
{
    while (true)
    {
        int leftChild = index * 2 + 1;
        int pos = index;
        if (leftChild < heapSize && nums[leftChild] > nums[pos])
            pos = leftChild;
        if (leftChild + 1 < heapSize && nums[leftChild + 1] > nums[pos])
            pos = leftChild + 1;
        if (pos == index)
            break;
        swap(nums[pos], nums[index]);
        index = pos;
    }
}
void BuildHeap(vector<int>& nums, int heapSize)
{
    for (int i = (heapSize - 2) / 2; i >= 0; --i)
    {
        Heapify(nums, i, heapSize);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    BuildHeap(nums, nums.size());
    int heapSize = nums.size();
    for (int i = heapSize - 1; i > nums.size() - k; --i)
    {
        swap(nums[0], nums[i]);
        heapSize--;
        Heapify(nums, 0, heapSize);
    }
    return nums[0];
}
