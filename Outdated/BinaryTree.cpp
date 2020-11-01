/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 06:27:03 PM PST
 ************************************************************************/
#include "BinaryTree.h"
#include<queue>
#include<iostream>
using namespace std;

void DestroyTree(TreeNode* pRoot)
{
    if (pRoot != nullptr)
    {
        DestroyTree(pRoot->m_pLeft);
        DestroyTree(pRoot->m_pRight);
        delete pRoot;
    }
}

void ConnectNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintNodeInBFS(TreeNode* pRoot)
{
    if (pRoot == nullptr)
        return;
    queue<TreeNode*> nodeQue;
    nodeQue.push(pRoot);
    while (!nodeQue.empty())
    {
        int numbers = nodeQue.size();
        for (int i = 0; i < numbers; ++i)
        {
            TreeNode* pNode = nodeQue.front();
            printf("%d ", pNode->m_nValue);
            nodeQue.pop();
            if (pNode->m_pLeft != nullptr)
                nodeQue.push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                nodeQue.push(pNode->m_pRight);
        }
        printf("\n");
    }
}
