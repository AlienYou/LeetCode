/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 *
 * https://leetcode.com/problems/vowel-spellchecker/description/
 *
 * algorithms
 * Medium (47.64%)
 * Likes:    273
 * Dislikes: 585
 * Total Accepted:    28.1K
 * Total Submissions: 54.4K
 * Testcase Example:  '["KiTe","kite","hare","Hare"]\n["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]'
 *
 * Given a wordlist, we want to implement a spellchecker that converts a query
 * word into a correct word.
 * 
 * For a given query word, the spell checker handles two categories of spelling
 * mistakes:
 * 
 * 
 * Capitalization: If the query matches a word in the wordlist
 * (case-insensitive), then the query word is returned with the same case as
 * the case in the wordlist.
 * 
 * 
 * Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
 * Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
 * Example: wordlist = ["yellow"], query = "yellow": correct =
 * "yellow"
 * 
 * 
 * Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the
 * query word with any vowel individually, it matches a word in the wordlist
 * (case-insensitive), then the query word is returned with the same case as
 * the match in the wordlist.
 * 
 * Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
 * Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no
 * match)
 * Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no
 * match)
 * 
 * 
 * 
 * 
 * In addition, the spell checker operates under the following precedence
 * rules:
 * 
 * 
 * When the query exactly matches a word in the wordlist (case-sensitive), you
 * should return the same word back.
 * When the query matches a word up to capitlization, you should return the
 * first such match in the wordlist.
 * When the query matches a word up to vowel errors, you should return the
 * first such match in the wordlist.
 * If the query has no matches in the wordlist, you should return the empty
 * string.
 * 
 * 
 * Given some queries, return a list of words answer, where answer[i] is the
 * correct word for query = queries[i].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: wordlist = ["KiTe","kite","hare","Hare"], queries =
 * ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
 * Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= wordlist.length <= 5000
 * 1 <= queries.length <= 5000
 * 1 <= wordlist[i].length <= 7
 * 1 <= queries[i].length <= 7
 * All strings in wordlist and queries consist only of english letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;
        for (string w : wordlist) {
            string low = tolow(w);
            string ve = todev(w);
            cap.insert({low, w});
            vow.insert({ve, w});
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (words.count(queries[i]))
                continue;
            string low = tolow(queries[i]);
            string v = todev(queries[i]);
            if (cap.count(low))
                queries[i] = cap[low];
            else if (vow.count(v))
                queries[i] = vow[v];
            else
                queries[i] = "";
        }
        return queries;
    }
    
    string tolow(string s) {
        for (auto& c : s)
            c = tolower(c);
        return s;
    }
    string todev(string s) {
        s = tolow(s);
        for (auto& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return s;
    }
};
// @lc code=end

