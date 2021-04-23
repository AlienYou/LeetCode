/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (46.28%)
 * Likes:    5490
 * Dislikes: 66
 * Total Accepted:    350K
 * Total Submissions: 741.4K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following three operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance1(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = i;
        }
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[j - 1] == word2[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            dp[i] = i;
        }
        int pre = 0;
        for (int i = 1; i <= n; ++i) {
            pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                if (word2[i - 1] == word1[j - 1]) {
                    dp[j] = pre;
                } else {
                    dp[j] = min(min(pre, dp[j - 1]), dp[j]) + 1;
                }
                pre = temp;
            }
        }
        return dp[m];
    }
};
// @lc code=end

