/*************************************************************************
	> File Name: LeetCode_876.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Mar 2020 06:49:24 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

sruct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* middleNode(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    ListNode* pFast = head;
    ListNode* pSlow = head;
    while (pFast != nullptr && pFast->next != nullptr)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
    return pSlow;
}
