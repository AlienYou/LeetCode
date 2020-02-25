/*************************************************************************
	> File Name: LeetCode.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Feb 2020 05:25:51 PM PST
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

int RangeSumBST(TreeNode* root, int L, int R)
{
    if (root == nullptr)
        return 0;
    int sum = 0;
    if (root->m_nValue < L)
        sum += RangeSumBST(root->m_pRight, L, R);
    else if (root->m_nValue > R)
        sum += RangeSumBST(root->m_pLeft, L, R);
    else
        sum += root->m_nValue + RangeSumBST(root->m_pLeft, L, R) + RangeSumBST(root->m_pRight, L, R);
    return sum;
}

void test(const char* testName, TreeNode* root, int L, int R, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int sum = RangeSumBST(root, L, R);
    if (sum == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", sum);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(10);
    TreeNode* pNode2 = new TreeNode(5);
    TreeNode* pNode3 = new TreeNode(15);
    TreeNode* pNode4 = new TreeNode(3);
    TreeNode* pNode5 = new TreeNode(7);
    TreeNode* pNode6 = new TreeNode(18);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    ConnectNodes(pNode3, nullptr, pNode6);

    test("Test1", pNode1, 7, 15, 32);
}

void test2()
{
    TreeNode* pNode1 = new TreeNode(10);
    TreeNode* pNode2 = new TreeNode(5);
    TreeNode* pNode3 = new TreeNode(15);
    TreeNode* pNode4 = new TreeNode(3);
    TreeNode* pNode5 = new TreeNode(7);
    TreeNode* pNode6 = new TreeNode(18);
    TreeNode* pNode7 = new TreeNode(13);
    TreeNode* pNode8 = new TreeNode(1);
    TreeNode* pNode9 = new TreeNode(6);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    ConnectNodes(pNode3, pNode7, pNode6);
    ConnectNodes(pNode4, pNode8, nullptr);
    ConnectNodes(pNode5, pNode9, nullptr);

    test("Test1", pNode1, 6, 10, 23);
}

int main()
{
    test1();
    test2();
}
