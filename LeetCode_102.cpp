/*************************************************************************
	> File Name: LeetCode_102.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Apr 2020 08:12:19 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levelTra;
    if (root == nullptr)
        return levelTra;
    queue<TreeNode*> treeQue;
    treeQue.push(root);
    while (!treeQue.empty())
    {
        vector<int> curLevl;
        int size = treeQue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* pNode = treeQue.front();
            treeQue.pop();
            curLevl.push_back(pNode->val);
            if (pNode->left != nullptr)
                treeQue.push(pNode->left);
            if (pNode->right != nullptr)
                treeQue.push(pNode->right);
        }
        levelTra.emplace_back(curLevl);
    }
    return levelTra;
}
