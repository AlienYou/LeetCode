/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (41.34%)
 * Likes:    6183
 * Dislikes: 289
 * Total Accepted:    723.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //dp version
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        unordered_set<string> set;
        for (const auto& ele : wordDict)
            set.insert(ele);
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    
    //DFS
    bool wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (const auto& ele : wordDict)
            set.insert(ele);
        memo.resize(s.length(), -1);
        return dfs(set, 0, s);
    }
    bool dfs(unordered_set<string>& set, int curInd, string& s) {
        if (curInd == s.length() || memo[curInd] == 1)
            return true;
        if (memo[curInd] == 0)
            return false;
        for (int i = 1; i <= s.length(); ++i) {
            string sub = s.substr(curInd, i);
            if (set.count(sub) && dfs(set, curInd + i, s)) {
                memo[curInd] = true;
                return true;
            }
        }
        memo[curInd] = 0;
        return false;
    }
    vector<int> memo;
};
// @lc code=end

