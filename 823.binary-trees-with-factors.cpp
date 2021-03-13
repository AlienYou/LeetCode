/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 *
 * https://leetcode.com/problems/binary-trees-with-factors/description/
 *
 * algorithms
 * Medium (36.24%)
 * Likes:    516
 * Dislikes: 58
 * Total Accepted:    20.8K
 * Total Submissions: 50.4K
 * Testcase Example:  '[2,4]'
 *
 * Given an array of unique integers, arr, where each integer arr[i] is
 * strictly greater than 1.
 * 
 * We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children.
 * 
 * Return the number of binary trees we can make. The answer may be too large
 * so return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2]
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,4,5,10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10,
 * 2, 5], [10, 5, 2].
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 2 <= arr[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1000000007;
        unordered_map<int, int> map;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long> dp(n, 1);
        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (map.count(right)) {
                        dp[i] = (dp[i] + dp[map[right]] * dp[j]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for (const auto& ele : dp) ans += ele;
        return ans % MOD;
    }
};
// @lc code=end

