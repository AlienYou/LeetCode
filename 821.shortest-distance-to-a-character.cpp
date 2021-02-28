/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (67.69%)
 * Likes:    1391
 * Dislikes: 93
 * Total Accepted:    83.6K
 * Total Submissions: 121.7K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string s and a character c that occurs in s, return an array of
 * integers answer where answer.length == s.length and answer[i] is the
 * shortest distance from s[i] to the character c in s.
 * 
 * 
 * Example 1:
 * Input: s = "loveleetcode", c = "e"
 * Output: [3,2,1,0,1,0,0,1,2,2,1,0]
 * Example 2:
 * Input: s = "aaab", c = "b"
 * Output: [3,2,1,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s[i] and c are lowercase English letters.
 * c occurs at least once in s.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> result(s.length(), s.length());
        int L = s.length();
        int i = 0;
        int eIndex = -L;
        for (; i < L; ++i) {
            if (s[i] == c)
                eIndex = i;
            result[i] = i - eIndex;
        }
        i = L - 1;
        eIndex = INT_MAX;
        for (; i >= 0; --i) {
            if (s[i] == c)
                eIndex = i;
            result[i] = min(result[i], eIndex - i);
        }
        return result;
    }
};
// @lc code=end

