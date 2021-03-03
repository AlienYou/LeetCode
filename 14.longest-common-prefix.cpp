/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.95%)
 * Likes:    3763
 * Dislikes: 2141
 * Total Accepted:    958.6K
 * Total Submissions: 2.7M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        root = new TrieNode(0);
        
        for (int i = 0; i < strs.size(); ++i) {
            constructNode(strs[i]);
        }
        string res;
        TrieNode* node = root;
        int i = 0;
        while (!node->isEnd && node->size == 1) {
            res += strs[0][i];
            node = node->next[strs[0][i] - 'a'];
            ++i;
        }
        return res;
    }
    
private:
    struct TrieNode{
        char ch;
        int size;
        bool isEnd = false;
        vector<TrieNode*> next;
        TrieNode(char c) : ch(c), size(0), isEnd(false), next(26, nullptr) { }
    };
    
    void constructNode(const string& str) {
        TrieNode* node = root;
        
        for (int i = 0; i < str.length(); ++i) {
            int ind = str[i] - 'a';
            if (node->next[ind] == nullptr) {
                node->size++;
                node->next[ind] = new TrieNode(str[i]);
            }
            node = node->next[ind];
        }
        node->isEnd = true;
    }
    
    TrieNode* root;
};
// @lc code=end

