/*************************************************************************
	> File Name: LeetCode_141.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Mar 2020 08:05:22 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode* pFast = head;
    ListNode* pSlow = head;
    while (pFast != nullptr && pFast->next != nullptr)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast)
            return true;
    }
    return false;
}
