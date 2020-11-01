/*************************************************************************
	> File Name: LeetCode_27.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Feb 2020 11:29:25 PM PST
 ************************************************************************/

#include<iostream>
#include<queue>
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

void PrintTree(TreeNode* pRoot)
{
    if (pRoot != nullptr)
    {
        queue<TreeNode*> queueNode;
        queueNode.push(pRoot);

        while (!queueNode.empty())
        {
            TreeNode* pNode = queueNode.front();
            printf("%d ", pNode->m_nValue);
            if (pNode->m_pLeft != nullptr)
                queueNode.push(pNode->m_pLeft);
            if (pNode->m_pRight != nullptr)
                queueNode.push(pNode->m_pRight);
            queueNode.pop();
        }
        printf("\n");
    }
}

void MirrorNodes(TreeNode* pRoot)
{
    if (pRoot == nullptr)
        return;
    TreeNode* pLeft = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = pLeft;
    MirrorNodes(pRoot->m_pLeft);
    MirrorNodes(pRoot->m_pRight);
}

TreeNode* MirrorTree(TreeNode* pRoot)
{
   if (pRoot == nullptr)
        return nullptr;
    MirrorNodes(pRoot);
    return pRoot;
}

void test(const char* testName, TreeNode* pRoot)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    printf("origin:");
    PrintTree(pRoot);
    printf("Mirror:");
    MirrorTree(pRoot);
    PrintTree(pRoot);
    DestroyTree(pRoot);
}

void test1()
{
    TreeNode* pNode1 = new TreeNode(4);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(7);
    TreeNode* pNode4 = new TreeNode(1);
    TreeNode* pNode5 = new TreeNode(3);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode7 = new TreeNode(9);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    ConnectNodes(pNode3, pNode6, pNode7);

    test("Test1", pNode1);
}

void test2()
{
    TreeNode* pNode1 = new TreeNode(4);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(7);
    TreeNode* pNode4 = new TreeNode(1);

    ConnectNodes(pNode1, pNode2, nullptr);
    ConnectNodes(pNode2, pNode3, nullptr);
    ConnectNodes(pNode3, pNode4, nullptr);

    test("Test2", pNode1);
}

void test4()
{
    TreeNode* pNode1 = new TreeNode(4);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(7);
    TreeNode* pNode4 = new TreeNode(1);
    TreeNode* pNode5 = new TreeNode(3);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode7 = new TreeNode(9);

    ConnectNodes(pNode1, pNode2, pNode3);
    ConnectNodes(pNode2, pNode4, pNode5);
    ConnectNodes(pNode3, pNode6, nullptr);
    ConnectNodes(pNode6, nullptr, pNode7);

    test("Test4", pNode1);
}

void test3()
{
    test("Test3", nullptr);
}
int main()
{
    test1();    
    test2();
    test3();
    test4();
}
