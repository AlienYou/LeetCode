/*************************************************************************
	> File Name: LeetCode_98.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Apr 2020 02:15:06 AM PDT
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

bool isValidBST(TreeNode* root) {
    if (root == nullptr)
        return true;
    stack<TreeNode*> nodeStack;
    TreeNode* pLast = nullptr;
    TreeNode* pNode = root;
    while (pNode != nullptr || !nodeStack.empty())
    {
        if (pNode != nullptr)
        {
            nodeStack.push(pNode);
            pNode = pNode->left;
        }
        else
        {
            pNode = nodeStack.top();
            nodeStack.pop();
            if (pLast == nullptr)
                pLast = pNode;
            else if (pLast->val >= pNode->val)
                return false;
            pLast = pNode;
            pNode = pNode->right;
        }
    }
    return true;
}
