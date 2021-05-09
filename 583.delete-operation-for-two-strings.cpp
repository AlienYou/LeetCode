/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    1762
 * Dislikes: 38
 * Total Accepted:    80.2K
 * Total Submissions: 154.7K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 * 
 * In one step, you can delete exactly one character in either string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "sea", word2 = "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "leetcode", word2 = "etco"
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 500
 * word1 and word2 consist of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m + n - 2 * dp[m][n];
    }

    int minDistance1(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> mem(m, vector<int>(n, 0));
        return m + n - 2 * dfs(word1, word2, m - 1, n - 1, mem);
    }
    
    int dfs(string& word1, string& word2, int i, int j, vector<vector<int>>& mem) {
        if (i < 0 || j < 0)
            return 0;
        if (mem[i][j] > 0)
            return mem[i][j];
        if (word1[i] == word2[j])
            mem[i][j] = 1 + dfs(word1, word2, i - 1, j - 1, mem);
        else 
            mem[i][j] = max(dfs(word1, word2, i - 1, j, mem), dfs(word1, word2, i, j - 1, mem));
        return mem[i][j];
    }
};
// @lc code=end

