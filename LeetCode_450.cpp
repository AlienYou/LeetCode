/*************************************************************************
	> File Name: LeetCode_450.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 16 May 2020 04:48:08 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
        {
            TreeNode* successor = moveNode(root->right);
            successor->left = root->left;
            root = successor;
        }
    }
    return root;
}
TreeNode* moveNode(TreeNode* root)
{
    if (root->left == nullptr)
        return root;
    TreeNode* pre = root;
    TreeNode* cur = root->left;
    while (cur->left != nullptr)
    {
        pre = cur;
        cur = cur->left;
    }   
    pre->left = cur->right;
    cur->right = root;
    return cur;
}
