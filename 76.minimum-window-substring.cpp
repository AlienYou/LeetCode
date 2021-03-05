/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.61%)
 * Likes:    6130
 * Dislikes: 414
 * Total Accepted:    503.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t, return the minimum window in s which will contain
 * all the characters in t. If there is no such window in s that covers all
 * characters in t, return the empty string "".
 * 
 * Note that If there is such a window, it is guaranteed that there will always
 * be only one unique minimum window in s.
 * 
 * 
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(n) time?
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(60, 0);
        for (int i = 0; i < t.length(); ++i) {
            count[t[i] - 'A']++;
        }
        int remain = t.length();
        int left = 0, right = 0, minStart = 0, minLen = INT_MAX;
        while (right < s.length()) {
            if (--count[s[right++] - 'A'] >= 0) --remain;
            while (remain == 0) {
                if (right - left < minLen) {
                    minLen = right -left;
                    minStart = left;
                }
                if (++count[s[left++] - 'A'] > 0) ++remain;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
// @lc code=end

