/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (55.23%)
 * Likes:    1896
 * Dislikes: 109
 * Total Accepted:    114.7K
 * Total Submissions: 204.6K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * Given a list of words, each word consists of English lowercase letters.
 * 
 * Let's say word1 is a predecessor of word2 if and only if we can add exactly
 * one letter anywhere in word1 to make it equal to word2. For example, "abc"
 * is a predecessor of "abac".
 * 
 * A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >=
 * 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of
 * word_3, and so on.
 * 
 * Return the longest possible length of a word chain with words chosen from
 * the given list of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chain is "a","ba","bda","bdca".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of English lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](string& s1, string& s2) { return s1.length() < s2.length();});
        int ans = 0;
        for (string& curStr : words) {
            int curMax = 1;
            for (int i = 0; i < curStr.length(); ++i) {
                string subStr = curStr.substr(0, i) + curStr.substr(i + 1);
                if (dp.find(subStr) != dp.end()) {
                    curMax = max(curMax, dp[subStr] + 1);
                }
            }
            dp[curStr] = curMax;
            ans = max(ans, curMax);
        }
        return ans;
    }
    unordered_map<string, int> mem;
    int longestStrChain(vector<string>& words) {
        auto cmp = [](string& s1, string& s2) { return s1.length() < s2.length(); };
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> set(words.begin(), words.end());
        int n = words.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, dfs(words[i], set));
        }
        return ans;
    }
    
    int dfs(string& s, unordered_set<string>& set) {
        if (s.length() == 0)
            return 0;
        if (mem.find(s) != mem.end())
            return mem[s];
        int ans = 1;
        for (int i = 0; i < s.length(); ++i) {
            string subStr = s.substr(0, i) + s.substr(i + 1);
            if (set.find(subStr) != set.end()) {
                ans = max(ans, 1 + dfs(subStr, set));
            }
        }
        mem[s] = ans;
        return ans;
    }
};
// @lc code=end

