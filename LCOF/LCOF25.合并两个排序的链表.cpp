class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* newNode = &dummy;
        while (l1 || l2) {
            if (l1 == nullptr) {
                newNode->next = l2;
                l2 = nullptr;
                break;
            } else if (l2 == nullptr) {
                newNode->next = l1;
                l1 = nullptr;
                break;
            }
            if (l1->val < l2->val) {
                newNode->next = l1;
                l1 = l1->next;
            } else {
                newNode->next = l2;
                l2 = l2->next;
            }
            newNode = newNode->next;
        }
        return dummy.next;
    }
};