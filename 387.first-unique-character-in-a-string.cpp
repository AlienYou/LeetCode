/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (53.70%)
 * Likes:    2682
 * Dislikes: 133
 * Total Accepted:    687.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string, find the first non-repeating character in it and return its
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode"
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contains only lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        for (const auto& ele : s) {
            count[ele - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

