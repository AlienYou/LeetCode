/*************************************************************************
	> File Name: LeetCode_199.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Apr 2020 09:31:32 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<int> result;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        int last;
        for (int i = 0; i < size; ++i)
        {
            TreeNode* pNode = que.front();
            que.pop();
            last = pNode->val;
            if (pNode->left != nullptr)
                que.push(pNode->left);
            if (pNode->right != nullptr)
                que.push(pNode->right);
        }
        if (size)
            result.push_back(last);
    }
    return result;
}

 void DFS(TreeNode* root, vector<int>& result, int depth)
{
    if (root == nullptr)
        return;
    if (depth + 1 > result.size())
        result.push_back(root->val);
    DFS(root->right, result, depth + 1);
    DFS(root->left, result, depth + 1);
}

vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<int> result;
    DFS(root, result, 0);
    return result;
}
