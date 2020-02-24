/*************************************************************************
	> File Name: LeetCode_offer24.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Feb 2020 06:53:50 PM PST
 ************************************************************************/
//反转链表
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

void DestroyList(ListNode* pHead)
{
    if (pHead != nullptr)
    {
        DestroyList(pHead->m_pNext);
        delete pHead;
    }
}

void PrintList(ListNode* pHead)
{
    if (pHead != nullptr)
    {
        printf("%d ", pHead->m_nValue);
        PrintList(pHead->m_pNext);
    }
}

ListNode* ReverseList(ListNode* head)
{
    if (head == nullptr)
        return nullptr;

    ListNode* pOrigNode = head;
    ListNode* ReverseNode = nullptr;
    
    while (pOrigNode != nullptr)
    {
        ListNode* pOpeNode = pOrigNode;
        pOrigNode = pOrigNode->m_pNext;
        pOpeNode->m_pNext = ReverseNode;
        ReverseNode = pOpeNode;
    }
    return ReverseNode;
}

void test(const char* testName, ListNode* pHead)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    printf("Origin:");
    PrintList(pHead);
    ListNode*reverseHead =  ReverseList(pHead);
    printf("Reverse:");
    PrintList(reverseHead);
    printf("\n");
    DestroyList(pHead);
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

    test("Test1", pNode1);
}

void test2()
{
    ListNode* pNode1 = new ListNode(1);

    test("Test2", pNode1);
}

int main()
{
    test1();
    test2();
}
