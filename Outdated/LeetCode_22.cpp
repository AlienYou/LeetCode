/*************************************************************************
	> File Name: LeetCode_22.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Feb 2020 06:03:29 PM PST
 ************************************************************************/

#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int val) : m_nValue(val), m_pNext(nullptr) {}
};

void ConnectNodes(ListNode* pNode, ListNode* pNext)
{
    if (pNode != nullptr)
        pNode->m_pNext = pNext;
}

void Destroy(ListNode* pHead)
{
    if (pHead != nullptr)
    {
        Destroy(pHead->m_pNext);
        delete pHead;
    }
}


ListNode* GetKthFromEnd(ListNode* pHead, int k)
{
    if (pHead == nullptr || k <= 0)
        return nullptr;
    
    ListNode* pNode = pHead;
    while (k > 1 && pNode != nullptr)
    {
        --k;
        pNode = pNode->m_pNext;
    }
    if (pNode == nullptr)
        return nullptr;
    ListNode* pKthNode = pHead;

    while (pNode != nullptr && pNode->m_pNext != nullptr)
    {
        pKthNode = pKthNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pKthNode;
}

void test(const char* testName, ListNode* pHead, int k, ListNode* pExpected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
   if (GetKthFromEnd(pHead, k) == pExpected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", GetKthFromEnd(pHead, k)->m_nValue);
}

void test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);
    ConnectNodes(pNode4, pNode5);

    test("Test1", pNode1, 2, pNode4);
}

void test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);
    ConnectNodes(pNode4, pNode5);
    ConnectNodes(pNode5, pNode6);

    test("Test2", pNode1, 1, pNode6); 
}

void test3()
{
    test("Test3", nullptr, 2, nullptr);
}

void test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);
    ConnectNodes(pNode4, pNode5);
    ConnectNodes(pNode5, pNode6);

    test("Test4", pNode1, 7, nullptr); 
}

void test5()
{
    ListNode* pNode1 = new ListNode(1);
    test("Test5", pNode1, 1, pNode1);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}

