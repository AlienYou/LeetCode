/*************************************************************************
	> File Name: BinaryTree_PostOrder.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 06:53:38 PM PST
 ************************************************************************/

#include<iostream>
#include"BinaryTree.h"
#include<stack>

using namespace std;

void PostOrder(TreeNode* pRoot)
{
    stack<TreeNode*> treeStack;
    TreeNode* pNode = pRoot;
    TreeNode* pTemp = nullptr;
    while (pNode != nullptr || !treeStack.empty())
    {
        if (pNode != nullptr)
        {
            treeStack.push(pNode);
            pNode = pNode->m_pLeft;
        }
        else
        {
            pNode = treeStack.top();
            if (pNode->m_pRight == nullptr || pNode->m_pRight == pTemp)
            {
                pTemp = pNode;
                printf("%d ", pNode->m_nValue);
                treeStack.pop();
                pNode = nullptr;
            }
            else
                pNode = pNode->m_pRight;
        }
    }
}

void test(const char* testName, TreeNode* pRoot)
{
    if (testName == nullptr)
        return;
    PostOrder(pRoot);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode6 = new TreeNode(6);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    ConnectNodes(pNode3, nullptr, pNode6);
    
    test("Test1", pNode1);
}

int main()
{
    test1();
}
