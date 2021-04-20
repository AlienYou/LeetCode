/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (45.83%)
 * Likes:    2171
 * Dislikes: 248
 * Total Accepted:    166.8K
 * Total Submissions: 355.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 * 
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [9], target = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 * 
 * 
 * 
 * Follow up: What if negative numbers are allowed in the given array? How does
 * it change the problem? What limitation we need to add to the question to
 * allow negative numbers?
 * 
 */

// @lc code=start
class Solution {
public:
    int combinationSum41(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int s = 1; s <= target; ++s) {
            for (int i = 0; i < nums.size(); ++i) {
                if (s - nums[i] >= 0)
                    dp[s] += dp[s - nums[i]];
            }
        }
        return dp[target];
    }
    vector<int> memo;
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target + 1, -1);
        memo[0] = 1;
        dfs(nums, target, target);
        return memo[target];
    }
    
    int dfs(vector<int>& nums, int cur, int target) {
        if (memo[cur] != -1) {
            return memo[cur];
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur - nums[i] >= 0) {
                res += dfs(nums, cur - nums[i], target);
            }
        }
        memo[cur] = res;
        return memo[cur];
    }
};
// @lc code=end

