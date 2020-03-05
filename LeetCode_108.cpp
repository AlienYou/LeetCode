/*************************************************************************
	> File Name: LeetCode_108.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Mar 2020 07:24:09 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include"BinaryTree.h"
using namespace std;

TreeNode* CreateBST(vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;
    int mid = left + ((right - left) >> 1);
    TreeNode* pNode = new TreeNode(nums[mid]);
    pNode->m_pLeft = CreateBST(nums, left, mid - 1);
    pNode->m_pRight = CreateBST(nums, mid + 1, right);
    return pNode;
}

TreeNode* SortedArrayToBST(vector<int>& nums)
{
    if (nums.size() == 0)
        return nullptr;
    return CreateBST(nums, 0, nums.size() - 1);
}

void test(const char* testName, vector<int>& nums)
{
   if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    TreeNode* pResult = SortedArrayToBST(nums);
    PrintNodeInBFS(pResult);
}

void test1()
{
    int nums[] = {-10, -3, 0, 5, 9};
    vector<int> vec(nums, nums + 5);
    test("Test1", vec);
}

int main()
{
    test1();
}


