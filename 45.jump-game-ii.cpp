/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (31.24%)
 * Likes:    3920
 * Dislikes: 176
 * Total Accepted:    328K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * You can assume that you can always reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end

