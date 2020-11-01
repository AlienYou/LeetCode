/*************************************************************************
	> File Name: LeetCode_114.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jun 2020 05:34:01 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
void flatten(TreeNode* root) {
    if (root == nullptr)
        return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* pCur = root;
    TreeNode* preNode = nullptr;
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        if (root->right != nullptr)
            st.push(root->right);
        if (root->left != nullptr)
            st.push(root->left);
        if (preNode != nullptr)
        {
            preNode->right = root;
            preNode->left = nullptr;    
        }
        preNode = root;
    }
}}
