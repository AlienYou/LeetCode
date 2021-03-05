/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (58.39%)
 * Likes:    5140
 * Dislikes: 160
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
class Solution {
public:
    public:
    void moveZeroes1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                int right = i + 1;
                while (right < nums.size() && nums[right] == 0)
                    right++;
                if (right < nums.size())
                    swap(nums[i], nums[right]);
            }
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        int nonZeroInd = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[nonZeroInd++], nums[i]);
            }
        }
    }
};
// @lc code=end

