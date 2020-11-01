/*************************************************************************
	> File Name: LeeetCode_1028.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jun 2020 09:43:17 PM PDT
 ************************************************************************/

#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
TreeNode* recoverFromPreorder1(string S) {
    stack<TreeNode*> st;
    int curIndex = 0;
    while (curIndex < S.length())
    {
        int curDepth = 0;
        while (S[curIndex] == '-')
        {
            ++curIndex;
            curDepth++;
        }
        int nodeValue = 0;
        while (curIndex < S.length() && isdigit(S[curIndex]))
        {
            nodeValue = nodeValue * 10 + (S[curIndex] - '0');
            curIndex++;
        }
        TreeNode* root = new TreeNode(nodeValue);
        if (curDepth == st.size()) 
        {
            if (!st.empty())
                st.top()->left = root;
        }
        else
        {
            while (st.size() > curDepth)
                st.pop();
            st.top()->right = root;
        }
        st.push(root);
    }
    while (st.size() > 1)
        st.pop();
    return st.top();
}
TreeNode* recoverFromPreorder(string S) {
    unordered_map<int, TreeNode*> tree;
    int index = 0;
    while (index < S.length())
    {
        int curDepth = 0;
        while (S[index] == '-')
        {
            curDepth++;
            index++;
        }
        int nodeValue = 0;
        while (index < S.length() && isdigit(S[index]))
        {
            nodeValue = nodeValue * 10 + (S[index] - '0');
            index++;
        }
        TreeNode* root = new TreeNode(nodeValue);
        if (!tree.count(curDepth - 1))
            tree[curDepth] = root;
        else
        {
            if (tree[curDepth - 1]->left != nullptr)
                tree[curDepth - 1]->right = root;
            else
                tree[curDepth - 1]->left = root;
            tree[curDepth] = root;
        }
    } 
    return tree[0];
}
