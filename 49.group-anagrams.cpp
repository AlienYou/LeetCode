/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (58.68%)
 * Likes:    4957
 * Dislikes: 224
 * Total Accepted:    862.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); ++i) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            map[cur].push_back(strs[i]);
        }
        for (const auto& ele : map) {
            result.push_back(ele.second);
        }
        return result;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        int count[26];
        for (int i = 0; i < strs.size(); ++i) {
            memset(count, 0, sizeof(count));
            for (const auto& ele : strs[i])
                count[ele - 'a']++;
            string key;
            for (int i = 0; i < 26; ++i) {
                key += "#";
                key += '0' + count[i];
            }
            map[key].push_back(strs[i]);
        }
        for (const auto& ele : map) {
            result.push_back(ele.second);
        }
        return result;
    }
};
// @lc code=end

