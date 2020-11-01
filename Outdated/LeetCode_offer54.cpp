/*************************************************************************
	> File Name: LeetCode_offer54.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Mar 2020 09:08:46 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include"BinaryTree.h"
using namespace std;

int KthLargest(TreeNode* root, int k)
{
    if (root == nullptr)
        return -1;
    vector<int> inorder;
    stack<TreeNode*> nodeStack;
    TreeNode* pNode = root;
    while (pNode != nullptr || !nodeStack.empty())
    {
        if (pNode != nullptr)
        {
            nodeStack.push(pNode);
            pNode = pNode->m_pLeft;
        }
        else
        {
            pNode = nodeStack.top();
            nodeStack.pop();
            inorder.push_back(pNode->m_nValue);
            pNode = pNode->m_pRight;
        }
    }
    return k < inorder.size()? inorder[inorder.size() - k] : -1;
}

int KthLargestCore(TreeNode* root, int k, int& count)
{
    if (root->m_pRight != nullptr)
        return KthLargestCore(root->m_pRight, k, count);
    if (++count == k)
        return root->m_nValue;
    if (root->m_pLeft != nullptr)
        return KthLargestCore(root->m_pLeft, k, count);
    return -1;
}

int KthLargest_Recursively(TreeNode* root, int k)
{
    if (root == nullptr)
        return 0;
    int count = 0;
    return KthLargestCore(root, k, count);
}

void test(const char* testName, TreeNode* pRoot, int k, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = KthLargest(pRoot, k);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", ans);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(3);
    TreeNode* pNode2 = new TreeNode(1);
    TreeNode* pNode3 = new TreeNode(4);
    TreeNode* pNode4 = new TreeNode(2);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, nullptr, pNode4);
    test("Test1", pNode1, 1, 4);
}

void test2()
{
    TreeNode* pNode1 = new TreeNode(3);
    TreeNode* pNode2 = new TreeNode(1);
    TreeNode* pNode3 = new TreeNode(4);
    TreeNode* pNode4 = new TreeNode(2);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, nullptr, pNode4);
    test("Test2", pNode1, 10, -1);
}

int main()
{
    test1();
    test2();
}
