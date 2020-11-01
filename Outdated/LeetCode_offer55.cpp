/*************************************************************************
	> File Name: LeetCode_offer55.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2020 09:11:15 PM PST
 ************************************************************************/

#include<iostream>

using namespace std;

struct TreeNode
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;

    TreeNode(int val) : m_nValue(val), m_pLeft(nullptr), m_pRight(nullptr) {}
};

void ConnectNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(TreeNode* pRoot)
{
    if (pRoot != nullptr)
    {
        DestroyTree(pRoot->m_pLeft);
        DestroyTree(pRoot->m_pRight);
        delete pRoot;
    }
}

int MaxDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    int left = MaxDepth(root->m_pLeft);
    int right = MaxDepth(root->m_pRight);
    
    return (left > right ? left : right) + 1;
}

void test(const char* testName, TreeNode* pRoot, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int depth = MaxDepth(pRoot);
    if (depth == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
    DestroyTree(pRoot);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);

    test("Test1", pNode1, 3);
}

void test2()
{
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);

    ConnectNodes(pNode1, pNode2, nullptr);
    ConnectNodes(pNode2, pNode3, nullptr);
    ConnectNodes(pNode3, pNode4, nullptr);
    ConnectNodes(pNode4, pNode5, nullptr);

    test("Test2", pNode1, 5);
}

int main()
{
    test1();
    test2();
}
