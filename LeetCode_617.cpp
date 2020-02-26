/*************************************************************************
	> File Name: LeetCode_617.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Feb 2020 10:18:36 PM PST
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

void Destroy(TreeNode* pRoot)
{
    if (pRoot != nullptr)
    {
        Destroy(pRoot->m_pLeft);
        Destroy(pRoot->m_pRight);
        delete pRoot;
    }
}

void Print(TreeNode* pRoot)
{
    if (pRoot != nullptr)
    {
        printf("%d ", pRoot->m_nValue);
        Print(pRoot->m_pLeft);
        Print(pRoot->m_pRight);
    }
}

TreeNode* MergeTrees(TreeNode* t1, TreeNode* t2)
{
    TreeNode* pMergeNode = nullptr;
    if (t1 != nullptr && t2 != nullptr)
    {    
        pMergeNode = new TreeNode(t1->m_nValue + t2->m_nValue);
        pMergeNode->m_pLeft = MergeTrees(t1->m_pLeft, t2->m_pLeft);
        pMergeNode->m_pRight = MergeTrees(t1->m_pRight, t2->m_pRight);
    }
     else if (t1 == nullptr && t2 != nullptr)
    {
        pMergeNode = new TreeNode(t2->m_nValue);
        pMergeNode->m_pLeft = MergeTrees(nullptr, t2->m_pLeft);
        pMergeNode->m_pRight = MergeTrees(nullptr, t2->m_pRight);
    }
    else if (t1 != nullptr && t2 == nullptr)
    {   
        pMergeNode = new TreeNode(t1->m_nValue);
        pMergeNode->m_pLeft = MergeTrees(t1->m_pLeft, nullptr);
        pMergeNode->m_pRight = MergeTrees(t1->m_pRight, nullptr);
    }
    return pMergeNode;
}

TreeNode* MergeTrees_2(TreeNode* t1, TreeNode* t2)
{
    if (t1 != nullptr && t2 != nullptr)
    {
        t1->m_nValue += t2->m_nValue;
        t1->m_pLeft = MergeTrees_2(t1->m_pLeft, t2->m_pLeft);
        t1->m_pRight = MergeTrees_2(t1->m_pRight, t2->m_pRight);
        delete t2;
    }
    return t1 == nullptr ? t2 : t1;
}

void test(const char* testName, TreeNode* t1, TreeNode* t2)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    TreeNode* pMergeRoot = MergeTrees(t1, t2);
    Print(pMergeRoot);
    printf("\n");
    Print(MergeTrees_2(t1, t2));
    printf("\n");
    Destroy(pMergeRoot);
    Destroy(t1);
    Destroy(t2);
}

void test1()
{
    TreeNode* pNode1_1 = new TreeNode(1);
    TreeNode* pNode1_2 = new TreeNode(3);
    TreeNode* pNode1_3 = new TreeNode(2);
    TreeNode* pNode1_4 = new TreeNode(5);

    ConnectNodes(pNode1_1, pNode1_2, pNode1_3);
    ConnectNodes(pNode1_2, pNode1_4, nullptr);

    TreeNode* pNode2_1 = new TreeNode(2);
    TreeNode* pNode2_2 = new TreeNode(1);
    TreeNode* pNode2_3 = new TreeNode(3);
    TreeNode* pNode2_4 = new TreeNode(4);
    TreeNode* pNode2_5 = new TreeNode(7);

    ConnectNodes(pNode2_1, pNode2_2, pNode2_3);
    ConnectNodes(pNode2_2, nullptr, pNode2_4);
    ConnectNodes(pNode2_3, nullptr, pNode2_5);

    test("Test1", pNode1_1, pNode2_1);
}

int main()
{
    test1();
}
