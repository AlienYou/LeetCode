/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (51.13%)
 * Likes:    3086
 * Dislikes: 98
 * Total Accepted:    298.2K
 * Total Submissions: 572.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * A palindrome string is a string that reads the same backward as forward.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<string>> partition1(string s) {
    //     vector<vector<string>> result;
    //     vector<string> currentList;
    //     dfs(result, s, 0, currentList);
    //     return result;
    // }
    vector<vector<string>> partition(string s) {
        int L = s.length();
        vector<vector<string>> result;
        vector<vector<bool>> dp(L, vector<bool>(L, false));
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }
    void dfs(vector<vector<string>>& result, string& s, int start, vector<string>& currentList, vector<vector<bool>>& dp) {
        if (start >= s.length()) {
            result.push_back(currentList);
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    } 
   
    bool isPalindrome(string& s, int left, int high) {
        while (left < high) {
            if (s[left] != s[high])
                return false;
            ++left, --high;
        } 
        return true;
    }
};
// @lc code=end

