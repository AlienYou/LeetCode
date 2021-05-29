/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (35.03%)
 * Likes:    753
 * Dislikes: 290
 * Total Accepted:    39.4K
 * Total Submissions: 110.8K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * Design a special dictionary with some words that searchs the words in it by
 * a prefix and a suffix.
 * 
 * Implement the WordFilter class:
 * 
 * 
 * WordFilter(string[] words) Initializes the object with the words in the
 * dictionary.
 * f(string prefix, string suffix) Returns the index of the word in the
 * dictionary, which has the prefix prefix and the suffix suffix. If there is
 * more than one valid index, return the largest of them. If there is no such
 * word in the dictionary, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["WordFilter", "f"]
 * [[["apple"]], ["a", "e"]]
 * Output
 * [null, 0]
 * 
 * Explanation
 * WordFilter wordFilter = new WordFilter(["apple"]);
 * wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix
 * = "a" and suffix = 'e".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 15000
 * 1 <= words[i].length <= 10
 * 1 <= prefix.length, suffix.length <= 10
 * words[i], prefix and suffix consist of lower-case English letters only.
 * At most 15000 calls will be made to the function f.
 * 
 * 
 */

// @lc code=start
class TrieNode {
public:
    int weight;
    vector<TrieNode*> children;
    TrieNode() : weight(0), children(27, nullptr) { }
};

class WordFilter {
public:
    TrieNode* root;
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int weight = 0; weight < words.size(); ++weight) {
            string word = words[weight] + '{';
            for (int i = 0; i < words[weight].length(); ++i) {
                TrieNode* cur = root;
                cur->weight = weight;
                for (int j = i; j < 2 * word.length() - 1; ++j) {
                    int k = word[j % word.length()] - 'a';
                    if (cur->children[k] == nullptr)
                        cur->children[k] = new TrieNode();
                    cur->children[k]->weight = weight;
                    cur = cur->children[k];
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + '{' + prefix;
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); ++i) {
            int k = word[i] - 'a';
            if (cur->children[k] == nullptr)
                return -1;
            cur = cur->children[k];
        }
        return cur->weight;
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

