/*************************************************************************
	> File Name: LeetCode_101.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 10:03:23 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
bool Core(TreeNode* root1, TreeNode* root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->val != root2->val)
        return false;
    return Core(root1->left, root2->right) && Core(root1->right, root2->left);
}  
bool isSymmetric1(TreeNode* root) {
    if (root == nullptr)
        return true;
    return Core(root->left, root->right);
}
bool isSymmetric2(TreeNode* root) {
    if (root == nullptr)
        return true;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<TreeNode*> v;
        for (int i = 0; i < size; ++i)
        {
            root = que.front();
            que.pop();
            v.push_back(root);
            if (root != nullptr)
            {
                que.push(root->left);
                que.push(root->right);
            }
        }
        int left = 0;
        int right = v.size() - 1;
        while (left < right)
        {
            if (v[left] != nullptr && v[right] != nullptr && v[left]->val != v[right]->val)
                return false;
            else if (v[left] == nullptr && v[right] != nullptr)
                return false;
            else if (v[left] != nullptr && v[right] == nullptr)
                return false;
            ++left;
            --right;
        }
    }    
    return true;
}
bool Check(TreeNode* u, TreeNode* v)
{
    queue<TreeNode*> que;
    que.push(u);
    que.push(v);
    while (!que.empty())
    {
        u = que.front();
        que.pop();
        v = que.front();
        que.pop();
        if(!u && !v)
            continue;
        if (!u || !v)
            return false;
        if (u->val != v->val)
            return false;
        que.push(u->left);
        que.push(v->right);

        que.push(u->right);
        que.push(v->left);
    }
    return true;
}
bool isSymmetric(TreeNode* root) {
    return Check(root, root);
}
