/*************************************************************************
	> File Name: LeetCode_189_RotateArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2020 06:46:07 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void PrintVec(vector<int>& nums);

void RotateInRange(vector<int>& nums, int start, int end)
{
    if (nums.size() == 0 || start < 0 || end >= nums.size())
        return;
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        ++start;
        --end;
    }
}

void RotateArray(vector<int>& nums, int k)
{
    if (k <= 0 || k == nums.size())
        return;
    
    if (k > nums.size())
        k %= nums.size();

    int start = 0;
    int end = nums.size() - 1;
    
    RotateInRange(nums, start, end);
    RotateInRange(nums, start, start + k - 1);
    RotateInRange(nums, start + k, end);
}

void RotateArray_2(vector<int>& nums, int k)
{
    if (nums.size() == 0 || k <= 0)
        return ;
    k %= nums.size();
    int count = 0;

    for (int start = 0; count < nums.size(); start++)
    {
        int pre = nums[start];
        int current = start;
        do
        {
            int next = (current + k) % nums.size();
            int temp = nums[next];
            nums[next] = pre;
            pre = temp;
            current = next;
            ++count;
        }while (start != current);
    }
}

void test(const char* testName, vector<int>& nums, int k)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    RotateArray_2(nums, k);
    PrintVec(nums);
}

void PrintVec(vector<int>& nums)
{
    vector<int>::const_iterator it = nums.begin();

    for(; it != nums.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}

void test1()
{
    int nums[] = {1, 2, 3, 4};
    vector<int> numsVec(nums, nums + 4);
    test("Test1", numsVec, 2);
}

void test2()
{
    int nums[] = {1, -44, 3, 99, 100};
    vector<int> numsVec(nums, nums + 5);
    test("Test2", numsVec, 3);
}

void test3()
{
    vector<int> nums;
    test("test3", nums, 0);
}

void test4()
{
    int nums[] = {1, 2, 3};
    vector<int> numsVec(nums, nums + 3);
    test("Test4", numsVec, 4);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
