class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode* node = head;
        while (node != nullptr) {
            ListNode* cur = node;
            node = node->next;
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};