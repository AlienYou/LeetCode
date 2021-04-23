/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (44.58%)
 * Likes:    4107
 * Dislikes: 204
 * Total Accepted:    352.1K
 * Total Submissions: 777.9K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isSame(int* map, int* pCount) {
        for (int i = 0; i < 26; ++i) {
            if (map[i] != pCount[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int l = s.length();
        int pl = p.length();
        int map[26];
        int pCount[26];
        memset(map, 0, sizeof(map));
        memset(pCount, 0, sizeof(pCount));
        for (const char& c : p)
            pCount[c - 'a']++;
        int left = 0, right = 0;
        
        vector<int> res;
        
        while (right < l) {
            map[s[right] - 'a']++;
            if (right - left + 1 == pl) {
                if (isSame(map, pCount))
                    res.push_back(left);
                map[s[left] - 'a']--;
                ++left;
            }
            ++right;
        }
        return res;
    }
};
// @lc code=end

