/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (37.89%)
 * Likes:    2522
 * Dislikes: 122
 * Total Accepted:    303.5K
 * Total Submissions: 781.8K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
 * 
 * 
 */

// @lc code=start
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
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        if (head->val == head->next->val) {
            ListNode* node = head; 
            int val = node->val;
            while (node && node->val == val) {
                ListNode* deleted = node;
                node = node->next;
                delete deleted;
            }
            head = node;
            head = deleteDuplicates(head);
        } else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        pre->next = head;
        while (head && head->next) {
            if (head->val == head->next->val) {
                int val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                pre->next = head;
            } else {
                head = head->next;
                pre = pre->next;
            }
        }
        
        return dummy.next;
    }
};
// @lc code=end

