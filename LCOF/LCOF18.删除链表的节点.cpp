class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* node = head;
        while (node != nullptr && node->val != val) {
            pre = pre->next;
            node = node->next;
        }
        if (node == nullptr)
            return head;
        pre->next = node->next;
        return dummy.next;
    }
};