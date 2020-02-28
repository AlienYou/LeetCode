/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 06:27:03 PM PST
 ************************************************************************/
#include "BinaryTree.h"


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

