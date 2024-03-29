/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (79.92%)
 * Likes:    723
 * Dislikes: 1956
 * Total Accepted:    278.2K
 * Total Submissions: 345.4K
 * Testcase Example:  '"Hello"'
 *
 * Given a string s, return the string after replacing every uppercase letter
 * with the same lowercase letter.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "Hello"
 * Output: "hello"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "here"
 * Output: "here"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
};
// @lc code=end

