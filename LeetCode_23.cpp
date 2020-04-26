/*************************************************************************
	> File Name: LeetCode_23.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Apr 2020 09:44:04 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

 ListNode* MergeList(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr)
        return list2;
    else if (list2 == nullptr)
        return list1;
    ListNode* pMergeHead = nullptr;
    if(list1->val <= list2->val)
    {
        pMergeHead = list1;
        pMergeHead->next = MergeList(list1->next, list2);
    }
    else
    {
        pMergeHead = list2;
        pMergeHead->next = MergeList(list1, list2->next);
    }
    return pMergeHead;
}

ListNode* Merge(vector<ListNode*>& lists, int start, int end)
{
    if (start >= end)
        return lists[start];
    int mid = start + ((end - start) >> 1);
    ListNode* pNew1 = Merge(lists, start, mid);
    ListNode* pNew2 = Merge(lists, mid + 1, end);
    return MergeList(pNew1, pNew2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
        return nullptr;
    return Merge(lists, 0, lists.size() - 1);
}

struct Status
{
    int val;
    ListNode* ptr;
    bool operator<(const Status& rv)const
    {
        return val > rv.val;
    }
};
ListNode* mergeKLists2(vector<ListNode*>& lists) {
    priority_queue<Status> que;
    for (auto node : lists)
        que.push({node->val, node});
    ListNode head, *tail = &head;
    while (!que.empty())
    {
        Status pTop = que.top();
        que.pop();
        tail->next = pTop.ptr;
        if (pTop.ptr->next)
            que.push({pTop.ptr->next->val, pTop.ptr->next});
        tail = tail->next;
    }
    return head.next;
}
