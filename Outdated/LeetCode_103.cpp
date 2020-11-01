/*************************************************************************
	> File Name: LeetCode_103.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 May 2020 09:31:13 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    queue<TreeNode*> que;
    que.push(root);
    bool isOdd = true;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> cur(size, 0);
        for (int i = 0; i < size; ++i)
        {
            auto curNode = que.front();
            que.pop();
            if (isOdd)
                cur[i] = curNode->val;
            else
                cur[size - i - 1] = curNode->val;
            if (curNode->left)
                que.push(curNode->left);
            if (curNode->right)
                que.push(curNode->right);
        }
        isOdd = !isOdd;
        res.push_back(cur);
    }
    return res;
}
