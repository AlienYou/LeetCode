/*************************************************************************
	> File Name: LeetCode_offer0207.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Mar 2020 11:30:16 PM PDT
 ************************************************************************/

#include<iostream>
#include "List.h"
using namespace std;

ListNode* GetIntersectionNode(ListNode* headA, ListNode* headB)
{
    int countMax = 0;
    int countMin = 0;
    ListNode* pMaxList = headA;
    ListNode* pMinList = headB;
    while (pMaxList != nullptr)
    {
        ++countMax;
        pMaxList = pMaxList->m_pNext;
    }
    while (pMinList != nullptr)
    {
        ++countMin;
        pMinList = pMinList->m_pNext;
    }
    int diff = countMax - countMin;
    if (countMax < countMin)
    {
        pMaxList = headB;
        pMinList = headA;
        diff = -diff;
    }
    else
    {
        pMaxList = headA;
        pMinList = headB;
    }
    while (diff)
    {
        --diff;
        pMaxList = pMaxList->m_pNext;
    }

    while (pMaxList != nullptr && pMinList != nullptr && pMaxList != pMinList)
    {
        pMaxList = pMaxList->m_pNext;
        pMinList = pMinList->m_pNext;
    }
    return pMaxList;
}
ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
    ListNode* pList1 = headA;
    ListNode* pList2 = headB;
    while (pList1 != nullptr || pList2 != nullptr)
    {
        if (pList1 == pList2)   return pList1;
        if (pList1 == nullptr)
            pList1 = headB;
        else
            pList1 = pList1->m_pNext;
        if (pList2 == nullptr)
            pList2 = headA;
        else
            pList2 = pList2->m_pNext;
    }
    return nullptr;
}
void test(const char* testName, ListNode* headA, ListNode* headB)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    ListNode* pRes = GetIntersectionNode(headA, headB);
    if (pRes != nullptr)
        printf("%d\n", pRes->m_nValue);
    else
        printf("null\n");
}

void test1()
{
    ListNode* pNode1 = new ListNode(0);
    ListNode* pNode2 = new ListNode(9);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(2);
    ListNode* pNode5 = new ListNode(4);
    
    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);
    ConnectNodes(pNode4, pNode5);

    ListNode* pNode2_1 = new ListNode(3);

    ConnectNodes(pNode2_1, pNode4);

    test("Test1", pNode1, pNode2_1);
} 

int main()
{
    test1();
}
