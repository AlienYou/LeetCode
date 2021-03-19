/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (50.98%)
 * Likes:    1469
 * Dislikes: 254
 * Total Accepted:    126.4K
 * Total Submissions: 246.5K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 * 
 * Return the maximum product you can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int cuttingRope1(int n) {
        int maxPro = 0;
        dfs(n, 1, 0, maxPro);
        return maxPro;
    }
    
    void dfs(int rest, int res, int count, int& maxPro) {
        if (count > 1 && rest == 0) {
            maxPro = max(maxPro, res);
            return ;
        }
        for (int i = 1; i <= rest; ++i) {
            dfs(rest - i, res * i, count + 1, maxPro);
        }
    }
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j <= 3; ++j) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};
// @lc code=end

