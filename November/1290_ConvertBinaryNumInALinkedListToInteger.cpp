class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* pNode = head;
        int res = 0;
        while(pNode)
        {
            res = res * 2 + pNode->val;
            pNode = pNode->next;
        }
        return res;
    }
};