/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (35.00%)
 * Likes:    2183
 * Dislikes: 2266
 * Total Accepted:    828.3K
 * Total Submissions: 2.4M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.length() == 0)
            return 0;
        int L = needle.length();
        for (int i = 0; i + L - 1< haystack.length(); ++i) {
            int k = 0;
            for (; k < needle.length(); ++k) {
                if (haystack[i + k] != needle[k])
                    break;
            }
            if (k == needle.length())
                return i;
        }
        return -1;
    }
};
// @lc code=end

