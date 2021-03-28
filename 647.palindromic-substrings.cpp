/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (61.62%)
 * Likes:    3994
 * Dislikes: 134
 * Total Accepted:    268.3K
 * Total Submissions: 429K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int valid(string& s, int left, int right) {
        int res = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
            res++;
        }
        return res;
    }
    int countSubstrings1(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res += valid(s, i, i);
            res += valid(s, i, i + 1);
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int l = 0; l < s.length(); ++l) {
            for (int i = 0; i + l < s.length(); ++i) {
                if (l == 0) {
                    dp[l][i] = 1;
                    res++;
                } else if (l == 1) {
                    dp[l][i] = s[i] == s[i + l];
                    if (dp[l][i])
                        ++res;
                } else {
                    dp[l][i] = s[i] == s[l + i] && dp[l - 2][i + 1];
                    if (dp[l][i])
                        ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

