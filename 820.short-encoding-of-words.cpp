/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 *
 * https://leetcode.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (51.33%)
 * Likes:    337
 * Dislikes: 91
 * Total Accepted:    18.4K
 * Total Submissions: 35.2K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * A valid encoding of an array of words is any reference string s and array of
 * indices indices such that:
 * 
 * 
 * words.length == indices.length
 * The reference string s ends with the '#' character.
 * For each index indices[i], the substring of s starting from indices[i] and
 * up to (but not including) the next '#' character is equal to words[i].
 * 
 * 
 * Given an array of words, return the length of the shortest reference string
 * s possible of any valid encoding of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2,
 * 5].
 * words[0] = "time", the substring of s starting from indices[0] = 0 to the
 * next '#' is underlined in "time#bell#"
 * words[1] = "me", the substring of s starting from indices[1] = 2 to the next
 * '#' is underlined in "time#bell#"
 * words[2] = "bell", the substring of s starting from indices[2] = 5 to the
 * next '#' is underlined in "time#bell#"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["t"]
 * Output: 2
 * Explanation: A valid encoding would be s = "t#" and indices = [0].
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * words[i] consists of only lowercase letters.
 * 
 * 
 */

// @lc code=start
class TrieNode{
public:
    TrieNode() : count(0), next(26, nullptr) { }
    TrieNode* get(const char& c) {
        if (next[c - 'a'] == nullptr) {
            next[c - 'a'] = new TrieNode;
            ++count;
        }
        return next[c - 'a'];
    }
    int count;
    vector<TrieNode*> next;

};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<TrieNode*, int> nodes;
        TrieNode* trie = new TrieNode();
        
        for (int i = 0; i < words.size(); ++i) {
            TrieNode* cur = trie;
            for (int right = words[i].length() - 1; right >= 0; --right) {
                cur = cur->get(words[i][right]);
            }
            nodes[cur] = words[i].length() + 1;
        }
        int ans = 0;
        for (const auto& ele : nodes) {
            if (ele.first->count == 0) 
                ans += ele.second;
        }
        return ans;
    }
};
// @lc code=end

