/*************************************************************************
	> File Name: LeetCode_142.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 May 2020 07:17:05 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
ListNode *detectCycle1(ListNode *head) {
    if (head == nullptr)
        return head;
    set<ListNode*> nodeSet;
    while (head != nullptr)
    {
        if (nodeSet.find(head) != nodeSet.end())
            break;    
        nodeSet.insert(head);
        head = head->next;
    }
    return head;
}
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)
        return head;
    ListNode* pSlow = head;
    ListNode* pFast = head;
    while (pFast != nullptr && pFast->next != nullptr)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pFast == pSlow)
            break;
    }
    if (pFast == nullptr || pFast->next == nullptr)
        return nullptr;
    pSlow = head;
    while (pSlow != pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    return pSlow;
}
