/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (64.44%)
 * Likes:    1210
 * Dislikes: 97
 * Total Accepted:    88.4K
 * Total Submissions: 135.1K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\r\n"mouse"\r'
 *
 * Given an array of strings products and a string searchWord. We want to
 * design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with the searchWord. If there are more than three products
 * with a common prefix return the three lexicographically minimums products.
 * 
 * Return list of lists of the suggested products after each character of
 * searchWord is typed. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: products = ["havana"], searchWord = "tatiana"
 * Output: [[],[],[],[],[],[],[]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= products.length <= 1000
 * There are no repeated elements in products.
 * 1 <= Σ products[i].length <= 2 * 10^4
 * All characters of products[i] are lower-case English letters.
 * 1 <= searchWord.length <= 1000
 * All characters of searchWord are lower-case English letters.
 * 
 * 
 */

//第一眼想到的就是单词查找树，
//注意代码优雅，另外还是要封装成一棵树
//然后就是查找前缀了，注意技巧，直接用一个string去类似栈的方法操作

// @lc code=start
class Trie
{   
    class TrieNode {
    public:
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(26, nullptr) {}
    };
    TrieNode* root;
    
    void dfsWithPrefix(TrieNode* cur, string& word, vector<string>& result) {
        if (result.size() >= 3)
            return;
        if (cur->isWord)
            result.push_back(word);
        for (int i = 0; i < 26; ++i) {
            if (cur->children[i]) {
                word += 'a' + i;
                dfsWithPrefix(cur->children[i], word, result);
                word.pop_back();
            }
        }
    }
public:
    Trie() { root = new TrieNode(); }    

    void insert(string& s) {
        TrieNode* cur = root;
        for (int j = 0; j < s.length(); ++j) {
            int k = s[j] - 'a';
            if (cur->children[k] == nullptr)
                cur->children[k] = new TrieNode();
            cur = cur->children[k];
        }
        cur->isWord = true;
    }
    
     vector<string> getStartWithPrefix(string& prefix) {
         vector<string> result;
         TrieNode* cur = root;
         for (const auto& c : prefix) {
             int k = c - 'a';
             if (cur->children[k] == nullptr)
                 return result;
             cur = cur->children[k];
         }
         dfsWithPrefix(cur, prefix, result);
         return result;
     }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        vector<vector<string>> res;

        for(auto& s : products)
            trie.insert(s);
        string prefix;
        for (auto& c : searchWord) {
            prefix += c;
            res.push_back(trie.getStartWithPrefix(prefix));
        }
        return res;
    }
    
};
// @lc code=end

