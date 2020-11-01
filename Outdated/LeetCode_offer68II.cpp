/*************************************************************************
	> File Name: LeetCode_offer68II.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Mar 2020 10:24:24 PM PDT
 ************************************************************************/

#include<iostream>
#include"BinaryTree.h"
#include<list>
using namespace std;

bool GetPath(list<TreeNode*>& path, TreeNode* pNode, TreeNode* pSearch)
{
    if (pNode == nullptr)
        return false;
    path.push_back(pNode);

    if (pNode == pSearch)
        return true;
    bool find = GetPath(path, pNode->m_pLeft, pSearch) || GetPath(path, pNode->m_pRight, pSearch);
    if (!find)
        path.pop_back();
    return find;
}

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr)
        return nullptr;
    list<TreeNode*> listPath1;
    list<TreeNode*> listPath2;
    GetPath(listPath1, root, p);
    GetPath(listPath2, root, q);
    
    TreeNode* pAncestor = nullptr;
    list<TreeNode*>::const_iterator it1 = listPath1.begin();
    list<TreeNode*>::const_iterator it2 = listPath2.begin();
    while (it1 != listPath1.end() && it2 != listPath2.end())
    {
        if (*it1 == *it2)
            pAncestor = *it1;
        ++it1;
        ++it2;
    }
    return pAncestor;
}


TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q)
{
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode* pLeft = lowestCommonAncestor_2(root->m_pLeft, p, q);
        TreeNode* pRight = lowestCommonAncestor_2(root->m_pRight, p, q);
        if (pLeft == nullptr)
            return pRight;
        if (pRight == nullptr)
            return pLeft;
        return root;
}
