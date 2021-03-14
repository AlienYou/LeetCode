/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (34.13%)
 * Likes:    2966
 * Dislikes: 445
 * Total Accepted:    309.1K
 * Total Submissions: 885.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a string s and a dictionary of strings wordDict, add spaces in s to
 * construct a sentence where each word is a valid dictionary word. Return all
 * such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     unordered_map<int, vector<string>> ans;
    unordered_set<string> strSet;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (const auto& ele : wordDict) 
            strSet.insert(ele);
        DFS(s, 0);
        return ans[0];
    }
    void DFS(string& s, int ind) {
        if (ans.count(ind))
            return;
        if (ind >= s.length()) {
            ans[ind] = {""};
            return;
        }
        for (int i = 1; ind + i <= s.length(); ++i) {
            string sub = s.substr(ind, i);
            if (strSet.count(sub)) {
                DFS(s, ind + i);
                for (const string& suc : ans[ind + i]) 
                    ans[ind].push_back(suc.empty()? sub : sub + " " + suc);
            }
        }
    }
};
// @lc code=end

