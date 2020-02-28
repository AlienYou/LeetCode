/*************************************************************************
	> File Name: BinaryTree.h
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 06:27:25 PM PST
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

struct TreeNode
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
    TreeNode(int val) : m_nValue(val), m_pLeft(nullptr), m_pRight(nullptr) {}
};

void DestroyTree(TreeNode* pRoot);
void ConnectNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight);


#endif
