/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (48.49%)
 * Likes:    5443
 * Dislikes: 497
 * Total Accepted:    771K
 * Total Submissions: 1.6M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return vector<string>();
        int L = digits.length();
        vector<string> result;
        string curRes;
        core(digits, 0, L, curRes, result);
        return result;
    }
    
    void core(const string& digits, int curInd, int L, string& curRes, vector<string>& result) {
        if (curInd == L) {
            result.push_back(curRes);
            return;
        }
        string& str = charMap[digits[curInd] - '0'];
        for (int i = 0; i < str.length(); ++i) {
            curRes.push_back(str[i]);
            core(digits, curInd + 1, L, curRes, result);
            curRes.pop_back();
        }
    }
    
private:
    unordered_map<int, string> charMap = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"}, 
        {9, "wxyz"}
    };
};
// @lc code=end

