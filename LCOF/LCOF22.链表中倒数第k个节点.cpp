class Solution {
public:
    ListNode* getKthFromEnd1(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode* node = head;
        while (k != 1 && node != nullptr) {
            k--;
            node = node->next;
        }
        if (node == nullptr)
            return nullptr;
        ListNode * kthNode = head;
        while (node->next != nullptr) {
            kthNode = kthNode->next;
            node = node->next;
        }
        return kthNode;
    }
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        int t = 0;
        while (first != nullptr) {
            if (t >= k) second = second->next;
            first = first->next;
            t++;
        }
        return second;
    }
};