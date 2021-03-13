/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (30.49%)
 * Likes:    1322
 * Dislikes: 647
 * Total Accepted:    96.2K
 * Total Submissions: 312.9K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an integer array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * You may assume the input array always has a valid answer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,1,1,6,4]
 * Output: [1,6,1,5,1,4]
 * Explanation: [1,4,1,5,1,6] is also accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,2,2,3,1]
 * Output: [2,3,1,3,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5000
 * It is guaranteed that there will be an answer for the given input nums.
 * 
 * 
 * 
 * Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> help(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 1; i < nums.size(); i += 2)
            nums[i] = help[n--];
        for (int i = 0; i < nums.size(); i += 2)
            nums[i] = help[n--];
    }
};
// @lc code=end

