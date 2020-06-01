/*************************************************************************
	> File Name: LeetCode_572.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jun 2020 03:12:20 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
bool Check(TreeNode* s, TreeNode* t)
{
    if (!s && !t)
        return true;
    if (s == nullptr || t == nullptr || s->val != t->val)
        return false;
    return Check(s->left, t->left) && Check(s->right, t->right);
}

bool DFS(TreeNode* s, TreeNode* t)
{
    if (s == nullptr)
        return false;
    return Check(s, t) || DFS(s->right, t) || DFS(s->left, t);   
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    return DFS(s, t);
}
