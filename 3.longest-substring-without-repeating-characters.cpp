/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.05%)
 * Likes:    12973
 * Dislikes: 674
 * Total Accepted:    2M
 * Total Submissions: 6.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int result = 0;
        unordered_map<char, int> mymap;
        int left = 0, right = 0;
        int length = s.length();
        while (right < length) {
            mymap[s[right]]++;
            while (left < right && mymap.at(s[right]) > 1) {
                mymap[s[left]]--;
                ++left;
            }
            result = max(result, right - left + 1);
            ++right;
        }
        return result;
    }
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> mymap;
        int left = 0, right = 0;
        int length = s.length();
        while (right < length) {
            if (mymap.count(s[right])) {
                left = max(mymap[s[right]] + 1, left);
            }
            result = max(result, right - left + 1);
            mymap[s[right]] = right;
            ++right;
        }
        return result;
    }
};
// @lc code=end

