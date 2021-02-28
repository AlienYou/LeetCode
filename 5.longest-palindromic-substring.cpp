/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (30.08%)
 * Likes:    9627
 * Dislikes: 647
 * Total Accepted:    1.2M
 * Total Submissions: 3.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a"
 * Output: "a"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "ac"
 * Output: "a"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or upper-case),
 * 
 */

// @lc code=start
class Solution {
public:

    auto extendAroundCenter(const string& s, int left, int right)->pair<int, int> {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    
    string longestPalindrome(string s) {
        
        int resLeft = 0, resRight = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            auto [l1, r1] = extendAroundCenter(s, i, i);
            auto [l2, r2] = extendAroundCenter(s, i, i + 1);
            
            if (r1 - l1 > resRight - resLeft) {
                resLeft = l1;
                resRight = r1;
            }
            if (r2 - l2 > resRight - resLeft) {
                resLeft = l2;
                resRight = r2;
            }
        }
        return s.substr(resLeft, resRight - resLeft + 1);
    }
    string longestPalindrome1(string s) {
        int result = 0;
        int ansL = -1;
        int ansR = -1;
        for (int i = 0; i < s.length(); ++i) {
            int l = i;
            int j = s.length() - 1;
            for (; j >= l; --j) {
                int R = j;
                int L = l;
                while (L <= R) {
                    if (s[R] != s[L])
                        break;
                    L++;
                    R--;
                }
                if (L > R) {
                    if (j - l + 1 > result) {
                        ansL = l;
                        ansR = j;
                        result = j - l + 1;
                    }
                    break;
                }
            }
        }
        return s.substr(ansL, ansR - ansL + 1);
    }

    string longestPalindrome2(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = 1;
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.length())
                    ans = s.substr(i, l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

