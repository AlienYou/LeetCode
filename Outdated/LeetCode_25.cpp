/*************************************************************************
	> File Name: LeetCode_25.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 May 2020 11:07:04 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
pair<ListNode*, ListNode*> reverseNode(ListNode* head, ListNode* tail)
{
    ListNode* pre = tail->next;
    ListNode* p = head;
    while (pre != tail)
    {
        ListNode* pNode = p;
        p = p->next;
        pNode->next=  pre;
        pre = pNode;
    }
    return {tail, head};
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    ListNode* tail = head;
    ListNode* pPre = &dummy;
    while (head)
    {
        for (int i = 0; i < k - 1; ++i)
        {
            tail = tail->next;
            if (!tail)
                return dummy.next;
        }
        tie(head, tail) = reverseNode(head, tail);
        pPre->next = head;
        pPre = tail;
        head = tail->next;
        tail = head;
    }
    return dummy.next;
}
