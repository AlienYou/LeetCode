/*************************************************************************
	> File Name: LeetCode_105.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jun 2020 11:46:13 PM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> preorderIndex;
unordered_map<int, int> inorderIndex;
TreeNode* Core(vector<int>& preorder, vector<int>& inorder, int leftPre, int rightPre, int leftIn, int rightIn)
{
    if (leftPre > rightPre)
        return nullptr;
    TreeNode* root = new TreeNode(preorder[leftPre]);
    int rIn = inorderIndex[preorder[leftPre]];
    int rPre = leftPre + rIn - leftIn;
    root->left = Core(preorder, inorder, leftPre + 1, rPre, leftIn, rIn - 1);
    root->right = Core(preorder, inorder, rPre + 1, rightPre, rIn + 1, rightIn);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < preorder.size(); ++i)
    {    
        preorderIndex[preorder[i]] = i;
        inorderIndex[inorder[i]] = i;
    }
    return Core(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
