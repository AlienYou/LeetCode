/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (52.64%)
 * Likes:    1626
 * Dislikes: 666
 * Total Accepted:    224.4K
 * Total Submissions: 428K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly they also use english lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 * 
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographicaly in this alien language.
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 0)
            return true;
        vector<int> orderLevel(26, 0);
        for (int i = 0; i < order.length(); ++i) {
            orderLevel[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (!comp(words[i - 1], words[i], orderLevel))
                return false;
        }
        return true;
    }
    
    bool comp(string& s1, string& s2, vector<int>& orderLevel) {
        int l1 = s1.length(), l2 = s2.length();
        int i;
        for (i = 0; i < l1; ++i) {
            if (i >= l2)
                return false;
            int level1 = orderLevel[s1[i] - 'a'];
            int level2 = orderLevel[s2[i] - 'a'];
            if (level1 == level2)
                continue;
            if (level1 > level2)
                return false;
            else
                break;    
        }
        return true;
    }
};
// @lc code=end

