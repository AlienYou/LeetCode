/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (48.81%)
 * Likes:    4967
 * Dislikes: 284
 * Total Accepted:    641.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 * 
 * 
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve this problem without using the library's sort function?
 * Could you come up with a one-pass algorithm using only O(1) constant space?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors1(vector<int>& nums) {
        vector<int> count(3, 0);
        for (const auto& ele : nums) 
            count[ele]++;
        int ind = 0;
        for (int i = 0; i <= 2; ++i) {
            for (int c = 1; c <= count[i]; ++c) {
                nums[ind] = i;
                ind++;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; ++i) {
            if (nums[i] == 0)
                swap(nums[i], nums[left++]);
            else if (nums[i] == 2) {
                swap(nums[i--], nums[right--]);
            }
        }
    }
};
// @lc code=end

