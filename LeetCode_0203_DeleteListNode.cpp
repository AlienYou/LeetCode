/*************************************************************************
	> File Name: LeetCode_0203_DeleteListNode.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2020 05:18:59 PM PST
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
    if (pNode == nullptr)
        return;
    pNode->m_pNext = pNext;
}

void Destroy(ListNode* pNode)
{
    if (pNode != nullptr)
    {
        Destroy(pNode->m_pNext);
        delete pNode;
    }
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;
    ListNode* pNode = pHead;

    while (pNode != nullptr)
    {
        printf("%d ", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

void DeleteNode(ListNode* node)
{
    if (node == nullptr)
        return;
    ListNode* pNext = node->m_pNext;
    node->m_nValue = pNext->m_nValue;
    node->m_pNext = pNext->m_pNext;
    delete pNext;
}

void test(const char* testName, ListNode* pHead, ListNode* node)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    DeleteNode(node);
    PrintList(pHead);
}

void test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);

    test("Test1", pNode1, pNode3);
}

void test2()
{
    test("Test2", nullptr, nullptr);
}

int main()
{
    test1();    
    test2();
}
