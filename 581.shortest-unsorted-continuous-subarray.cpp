/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (31.58%)
 * Likes:    3521
 * Dislikes: 166
 * Total Accepted:    157.4K
 * Total Submissions: 490K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array nums, you need to find one continuous subarray that
 * if you only sort this subarray in ascending order, then the whole array will
 * be sorted in ascending order.
 * 
 * Return the shortest such subarray and output its length.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,6,4,8,10,9,15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: Can you solve it in O(n) time complexity?
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray1(vector<int>& nums) {
        stack<int> st;
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(st.top(), l);                
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                r = max(st.top(), r);
                st.pop();
            }
            st.push(i);
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                minVal = min(minVal, nums[i]);
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1])
                maxVal = max(maxVal, nums[i]);
        }
        
        int l = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > minVal) {
                l = i;
                break;
            }
        }
        
        int h = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < maxVal) {
                h = i;
                break;
            }
        }
        return h - l > 0 ? h - l + 1 : 0;
    }
};
// @lc code=end

