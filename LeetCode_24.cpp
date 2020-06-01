/*************************************************************************
	> File Name: LeetCode_24.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jun 2020 08:29:14 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

auto reverse(ListNode* head, ListNode* tail)->pair<ListNode*, ListNode*>
{
    ListNode* pre = tail->next;
    ListNode* p = head;
    while (pre != tail)
    {
        ListNode* pCur = p;
        p = p->next;
        pCur->next = pre;
        pre = pCur;
    }
    return {tail, head};
}
ListNode* swapPairs1(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* tail = head;
    ListNode* prev = &dummy;
    while (head != nullptr)
    {
        for (int i = 0; i < 1; ++i)
        {
            tail = tail->next;
            if (!tail)
                return dummy.next;
        }
        tie(head, tail) = reverse(head, tail);
        prev->next = head;
        prev = tail;
        head = tail->next;
        tail = head;
    }
    return dummy.next;
}
 ListNode* swapPairs2(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* firstNode = head;
    ListNode* SecondNode = head->next;
    firstNode->next = swapPairs(head->next->next);
    SecondNode->next = firstNode;
    return SecondNode;
 }
 ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (head != nullptr && head->next != nullptr) 
    {
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        prev->next = secondNode;
        head = firstNode->next;
        prev = firstNode;
    }
    return dummy.next;
 }
