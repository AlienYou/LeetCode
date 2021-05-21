/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (74.06%)
 * Likes:    1131
 * Dislikes: 95
 * Total Accepted:    71.9K
 * Total Submissions: 96K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * Given a list of strings words and a string pattern, return a list of
 * words[i] that match pattern. You may return the answer in any order.
 * 
 * A word matches the pattern if there exists a permutation of letters p so
 * that after replacing every letter x in the pattern with p(x), we get the
 * desired word.
 * 
 * Recall that a permutation of letters is a bijection from letters to letters:
 * every letter maps to another letter, and no two letters map to the same
 * letter.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a ->
 * m, b -> e, ...}. 
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
 * permutation, since a and b map to the same letter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","b","c"], pattern = "a"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pattern.length <= 20
 * 1 <= words.length <= 50
 * words[i].length == pattern.length
 * pattern and words[i] are lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for (int i = 0; i < words.size(); ++i) {
            if (match(words[i], pattern))
                res.push_back(words[i]);
        }
        return res;
    }
    
    bool match(string& word, string& pattern) {
        unordered_map<char, char> wordToPattern;
        unordered_map<char, char> patternToWord;
            
        for (int i = 0; i < word.length(); ++i) {
            if (wordToPattern.find(word[i]) == wordToPattern.end()) wordToPattern[word[i]] = pattern[i];
            if (patternToWord.find(pattern[i]) == patternToWord.end()) patternToWord[pattern[i]] = word[i];
            if (wordToPattern[word[i]] != pattern[i] || patternToWord[pattern[i]] != word[i])
                return false;
        }    
        return true;
    }
};
// @lc code=end

