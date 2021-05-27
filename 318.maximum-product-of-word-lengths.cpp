/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (51.98%)
 * Likes:    1217
 * Dislikes: 83
 * Total Accepted:    118.7K
 * Total Submissions: 219.5K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> value(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                value[i] |= 1 << (words[i][j] - 'a');
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(value[i] & value[j])) { 
                    int curL = words[i].length() * words[j].length();
                    ans = max(curL, ans);
                }
            }
        }
        return ans;
    }
    
    int maxProduct1(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        int charCount[26];
        for (int i = 0; i < n; ++i) {
            memset(charCount, 0, sizeof(charCount));
            log(charCount, words[i]);
            for (int j = i + 1; j < n; ++j) {
                if (isNotShare(charCount, words[j])) {
                    int cur = words[j].length() * words[i].length();
                    
                    ans = max(cur, ans);
                }
            }
        }
        return ans;
    }
    
    void log(int* charCount, string& s1) {
        for (int i = 0; i < s1.length(); ++i) {
            charCount[s1[i] - 'a']++;
        }
    }
    
    bool isNotShare(int* charCount, string& s2) {
        for (int i = 0; i < s2.length(); ++i) {
            if (charCount[s2[i] - 'a'] > 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

