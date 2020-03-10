/*************************************************************************
	> File Name: LeetCode_543.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Mar 2020 05:14:40 PM PDT
 ************************************************************************/

#include<iostream>
#include"BinaryTree.h"
using namespace std;

int maxPath = 0;
int Depth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int left = Depth(root->m_pLeft);
    int right = Depth(root->m_pRight);
    maxPath = max(left + right, maxPath);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    Depth(root); 
    return maxPath;
}

void test(const char* testName, TreeNode* root)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = diameterOfBinaryTree(root);
    printf("%d.\n", result);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);
    
    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    
    test("Test1", pNode1);
}

void test2()
{
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    
    ConnectNodes(pNode1, pNode2, nullptr);
    ConnectNodes(pNode2, pNode3, nullptr);
    ConnectNodes(pNode3, pNode4, nullptr);
    
    test("Test2", pNode1);
}

int main()
{
    test1();

    test2();
}
