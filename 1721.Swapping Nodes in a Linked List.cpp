/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode* kthNode = head;
        while (k != 1 && kthNode != nullptr){
            kthNode = kthNode->next;
            --k;
        }
        ListNode* firstKth = kthNode;
        ListNode* secondkthNode = head;
        while (kthNode->next != nullptr) {
            kthNode = kthNode->next;
            secondkthNode = secondkthNode->next;
        }
        swap(firstKth->val, secondkthNode->val);
        return head;
    }
};