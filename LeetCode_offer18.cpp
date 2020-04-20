/*************************************************************************
	> File Name: LeetCode_offer18.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Apr 2020 05:45:48 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
ListNode* deleteNode(ListNode* head, int val) {
    if (head == nullptr)
        return nullptr;
    if (head->val == val)
    {
        head = head->next;
        return head;
    }
    ListNode* pNode = head->next;
    ListNode* pPre = head;
    while (pNode != nullptr && pNode->val != val)
    {
        pNode = pNode->next;
        pPre = pPre->next;
    }
    if (pNode == nullptr)
        return head;
    pPre->next = pNode->next;
    return head;
}
ListNode* deleteNode1(ListNode* head, int val)
    if (!head) return nullptr;
        if (head->val == val) return head->next;
        head->next = deleteNode(head->next, val);
        return head;
}
