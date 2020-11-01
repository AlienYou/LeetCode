/*************************************************************************
	> File Name: LeetCode_offer25.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Feb 2020 06:16:19 PM PST
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
    {
        pNode->m_pNext = pNext;
    }
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

ListNode* MergeTwoList(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    
    ListNode* pNewHead = new ListNode(1);
    ListNode* pNewList = pNewHead;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->m_nValue <= l2->m_nValue)
        {    
            pNewList->m_pNext = l1;
            l1 = l1->m_pNext;
        }
        else
        {
            pNewList->m_pNext = l2;
            l2 = l2->m_pNext;
        }
        pNewList = pNewList->m_pNext;
    }
    if (l1 == nullptr)
        pNewList->m_pNext = l2;
    else 
        pNewList->m_pNext = l1;
    return pNewHead;
}

ListNode* MergeTwoList_Recursively(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;

    ListNode* pMergeHead = nullptr;

    if (l1->m_nValue <= l2->m_nValue)
    {
        pMergeHead = l1;
        pMergeHead->m_pNext = MergeTwoList_Recursively(l1->m_pNext, l2);
    }
    else
    {
        pMergeHead = l2;
        pMergeHead->m_pNext = MergeTwoList_Recursively(l1, l2->m_pNext);
    }
    return pMergeHead;
}

void test(const char* testName, ListNode* l1, ListNode* l2)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    ListNode* pNewHead = MergeTwoList_Recursively(l1, l2);
    PrintList(pNewHead);
    printf("\n");
    DestroyList(pNewHead);
}

void test1()
{
    ListNode* pNode1_1 = new ListNode(1);
    ListNode* pNode1_2 = new ListNode(2);
    ListNode* pNode1_3 = new ListNode(4);

    ConnectNodes(pNode1_1, pNode1_2);
    ConnectNodes(pNode1_2, pNode1_3);

    ListNode* pNode2_1 = new ListNode(1);
    ListNode* pNode2_2 = new ListNode(3);
    ListNode* pNode2_3 = new ListNode(4);

    ConnectNodes(pNode2_1, pNode2_2);
    ConnectNodes(pNode2_2, pNode2_3);

    test("Test1", pNode1_1, pNode2_1);
}

int main()
{
    test1();
}
