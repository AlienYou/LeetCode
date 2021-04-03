/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (44.70%)
 * Likes:    4169
 * Dislikes: 93
 * Total Accepted:    271.6K
 * Total Submissions: 604.3K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition1(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1)
            return false;
        sum >>= 1;
        if (maxNum > sum)
            return false;
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][sum];
    }
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1)
            return false;
        sum >>= 1;
        if (maxNum > sum)
            return false;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        dp[nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= nums[i])
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

