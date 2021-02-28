/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (26.12%)
 * Likes:    3985
 * Dislikes: 3384
 * Total Accepted:    526.4K
 * Total Submissions: 2M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * 
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 * 
 * 
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * 
 * 
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 * 
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 * 
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "0"
 * Output: 0
 * Explanation: There is no character that is mapped to a number starting with
 * 0.
 * The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of
 * which start with 0.
 * Hence, there are no valid ways to decode this since all digits need to be
 * mapped.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings1(string s) {
        if (s.length() == 0)
            return 0;
        int L = s.length();
        vector<int> dp(L + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < L; ++i) {
            if (charMap.count(s.substr(i, 1)))
                dp[i + 1] += dp[i];
            if (i - 1 >= 0 && charMap.count(s.substr(i - 1, 2))){
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[L];
    }
    
    int numDecodings(string s) {
        int L = s.length();
        vector<int> mem(L + 1, -1);
        mem[0] = 1;
        return DFS(L - 1, s, mem);
    }
    
    int DFS(int i, string& s, vector<int>& mem) {
        if (mem[i + 1] > -1) {
            return mem[i + 1];
        }
        
        int result = 0;
        if (s[i] == '0') {
           result = 0;
        } else
            result = DFS(i - 1, s, mem);
        if (i - 1 >= 0 && (s[i - 1] == '2' && s[i] < '7' || s[i - 1] == '1'))
            result += DFS(i - 2, s, mem);
        mem[i + 1] = result;
        return mem[i + 1];
    }
private: 
    unordered_set<string> charMap = {
        {"1"},
        {"2"},
        {"3"},
        {"4"},
        {"5"},
        {"6"},
        {"7"},
        {"8"},
        {"9"},
        {"10"},
        {"11"},
        {"12"},
        {"13"},
        {"14"},
        {"15"},
        {"16"},
        {"17"},
        {"18"},
        {"19"},
        {"20"},
        {"21"},
        {"22"},
        {"23"},
        {"24"},
        {"25"},
        {"26"},
    };
};
// @lc code=end

