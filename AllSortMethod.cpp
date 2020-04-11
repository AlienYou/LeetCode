/*************************************************************************
	> File Name: AllSortMethod.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Mar 2020 01:27:46 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//稳定排序，原地算法
void BubbleSort(vector<int>& nums)
{
    if (nums.size() <= 1)
        return;
    
    for (int i = nums.size() - 1; i > 0; --i)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
//稳定排序，原地算法
void InsertSort(vector<int>& nums)
{
    if (nums.size() <= 1)
        return;
    for (int i = 1; i < nums.size(); ++i)
    {
        int val = nums[i];
        int j;
        for (j = i - 1; j >= 0; --j)
        {
            if (nums[j] > val)
            {
                nums[j + 1] = nums[j];
            }
            else
                break;
        }
        nums[j + 1] = val;
    }
}

void SelectionSort(vector<int>& nums)
{
    if (nums.size() <= 1)
        return ;
    for (int i = 0; i < nums.size(); ++i)
    {
        int min = nums[i];
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (min > nums[j])
            {
                min = nums[j];
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

void MergeSortCore(vector<int>& nums, int start, int mid, int end)
{
    int* tempArr = new int[end - start + 1];
    int tempIndex = 0;
    int leftL = start, leftR = mid + 1;
    while (leftL <= mid && leftR <= end)
    {
        if (nums[leftL] <= nums[leftR])
        {
            tempArr[tempIndex++] = nums[leftL++];
        }
        else
        {
            tempArr[tempIndex++] = nums[leftR++];
        }
    }
    int endL = leftL, endR = mid;
    if (leftL > mid)
    {
        endL = leftR;
        endR = end;
    }

    while (endL <= endR)
    {
        tempArr[tempIndex++] = nums[endL++];
    }
    for (int i = start; i <= end; ++i)
        nums[i] = tempArr[i - start];
    delete[] tempArr;
}

//归并排序
void MergeSort(vector<int>& nums, int start, int end)
{
    printf("MergeSort:\n");
    if (nums.size() <= 1)
        return ;
    if (start >= end)
        return ;
    int mid = start + ((end - start) >> 1);
    MergeSort(nums, start, mid);
    MergeSort(nums, mid + 1, end);
    MergeSortCore(nums, start, mid, end);
}

//堆排序
void Heapify(vector<int>& nums, int n, int i)
{
    while (true)
    {
        int pos = i;
        if (i * 2 + 1 <= n && nums[i] < nums[i * 2 + 1]) pos = i * 2 + 1;
        if (i * 2 + 2 <= n && nums[pos] < nums[i * 2 + 2]) pos = i * 2 + 2;
        if (pos == i) break;
        swap(nums[i], nums[pos]);
        i = pos;
    }
}

void BuildHeap(vector<int>& nums)
{
    int size = nums.size() - 1;
    for (int i = (size - 1) / 2; i >= 0; --i)
        Heapify(nums, nums.size() - 1, i);
}

void HeapSort(vector<int>& nums)
{
    BuildHeap(nums);
    for (int i = nums.size() - 1; i > 0; --i)
    {
        swap(nums[0], nums[i]);
        Heapify(nums, i - 1, 0);
    }
}
//堆排序

void Print(vector<int>& nums)
{
    for (auto &x : nums)
        printf("%d ", x);
    printf("\n");
}

void testBubbleSort()
{
    vector<int> nums{4, 3, 2, 1, 2};
    BubbleSort(nums);
    Print(nums);
}

void testInsertSort()
{
    vector<int> nums{4, 2, 3, 1, 0, 6};
    InsertSort(nums);
    Print(nums);
}

void testSelectionSort()
{
    vector<int> nums{4, 2, 3, 1, 0, 2};
    SelectionSort(nums);
    Print(nums);
}

void testMergeSort()
{
    vector<int> nums{4, 2, 3, 5, 1, 0, 7};
    MergeSort(nums, 0, nums.size() - 1);
    Print(nums);
}

void testHeapSort()
{
    vector<int> nums{3, 2, 1, 5, 4};
    HeapSort(nums);
    Print(nums);
}


int main()
{
    //testBubbleSort();
    //testInsertSort();
    //testSelectionSort();
    //testMergeSort();
    testHeapSort();
}
