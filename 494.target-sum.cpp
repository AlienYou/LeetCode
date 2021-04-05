/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.88%)
 * Likes:    3916
 * Dislikes: 161
 * Total Accepted:    225.9K
 * Total Submissions: 495K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 * 
 * Example 1:
 * 
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));
        return DFS(nums, 0, 0, S, memo);
    }
    
    int DFS(vector<int>& nums, int ind, int curSum, int S, vector<vector<int>>& memo) {
        if (ind == nums.size()) {
            return curSum == S ? 1 : 0;
        }
        if (memo[ind][curSum + 1000] != INT_MIN)
            return memo[ind][curSum + 1000];
        int add = DFS(nums, ind + 1, curSum + nums[ind], S, memo);
        int sub = DFS(nums, ind + 1, curSum - nums[ind], S, memo);
        memo[ind][curSum + 1000] = add + sub;
        return memo[ind][curSum + 1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000 ] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int sum = -1000; sum <= 1000; ++sum) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] = dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
    }
};
// @lc code=end

