/*************************************************************************
	> File Name: LeetCode_445.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Apr 2020 12:09:40 AM PDT
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    stack<ListNode*> stL1;
    stack<ListNode*> stL2;
    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 != nullptr)
        {
            stL1.push(l1);
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            stL2.push(l2);
            l2 = l2->next;
        }
    }
    if (stL1.size() < stL2.size())
        swap(stL1, stL2);
    ListNode* pNew = nullptr;
    while (!stL1.empty() || !stL2.empty())
    {
        ListNode* pL1 = nullptr;
        ListNode* pL2 = nullptr;
        if(stL1.size() > 0)
        {
            pL1 = stL1.top();
            stL1.pop();
        }
        if (stL2.size() > 0)
        {
            pL2 = stL2.top();
            stL2.pop();
        }
        if(pL1 != nullptr && pL2 != nullptr)
        {
            pL1->val = pL1->val + pL2->val;
            pL2->val = pL1->val;
            pNew = pL1;
        }
        else if (pL1 != nullptr && pL2 == nullptr)
            pNew = pL1;
        if (pNew->next != nullptr && pNew->next->val >= 10)
        {
            pNew->val += 1;
            pNew->next->val %= 10;
        }
    }
    if (pNew->val >= 10)
    {
        ListNode* pAdd = new ListNode(1);
        pAdd->next = pNew;
        pNew->val %= 10;
        pNew = pAdd;
    }
    return pNew;
}
