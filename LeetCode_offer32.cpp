/*************************************************************************
	> File Name: LeetCode_offer32.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Feb 2020 07:58:23 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include "BinaryTree.h"
using namespace std;

vector<vector<int>> LevelOrder(TreeNode* root)
{
    vector<vector<int>> level; 
    if (root == nullptr)
        return level;
    TreeNode* pNode = root;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        vector<int> curLevel;
        for(int i = 0; i < n; ++i)
        {
            pNode = que.front();
            curLevel.push_back(pNode->m_nValue);
            que.pop();
            if (pNode->m_pLeft != nullptr)
                que.push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                que.push(pNode->m_pRight);
        }
        level.push_back(curLevel);
    }
    return level;
}

void test(const char* testName, TreeNode* root)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    vector<vector<int>> result = LevelOrder(root);
    for (auto &x : result)
    {
        for (auto &y : x)
        {
            printf("%d ", y);
        }
        printf("\n");
    }
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(3);
    TreeNode* pNode2 = new TreeNode(9);
    TreeNode* pNode3 = new TreeNode(20);
    TreeNode* pNode4 = new TreeNode(15);
    TreeNode* pNode5 = new TreeNode(7);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode3, pNode4, pNode5);

    test("Test1", pNode1);
}

int main()
{
    test1();
}
