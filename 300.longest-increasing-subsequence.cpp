/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.48%)
 * Likes:    6577
 * Dislikes: 151
 * Total Accepted:    504.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you come up with the O(n^2) solution?
 * Could you improve it to O(n log(n)) time complexity?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //     int lengthOfLIS(vector<int>& nums) {
//         return lengthOfLIS(nums, INT_MIN, 0);
//     }
    
//     int lengthOfLIS(vector<int>& nums, int prev, int curPos) {
//         if (curPos == nums.size())
//             return 0;
//         int taken = 0;
//         if (nums[curPos] > prev) {
//             taken = 1 + lengthOfLIS(nums, nums[curPos], curPos + 1);
//         }
//         int noTaken = lengthOfLIS(nums, prev, curPos + 1);
//         return max(noTaken, taken);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size(), -1));
        return lengthOfLIS(nums, -1, 0, memo);
    }
    
    int lengthOfLIS(vector<int>& nums, int prevIndex, int curPos, vector<vector<int>>& memo) {
        if (curPos == nums.size()) 
            return 0;
        if (memo[prevIndex + 1][curPos] >= 0)
            return memo[prevIndex + 1][curPos];
        int taken = 0;
        
        if (prevIndex < 0 || nums[curPos] > nums[prevIndex]) {
            taken = 1 + lengthOfLIS(nums, curPos, curPos + 1, memo);
        }
        
        int notaken = lengthOfLIS(nums, prevIndex, curPos + 1, memo);
        memo[prevIndex + 1][curPos] = max(taken, notaken);
        return memo[prevIndex + 1][curPos];
    }
};
// @lc code=end

