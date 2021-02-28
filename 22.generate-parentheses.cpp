/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (64.68%)
 * Likes:    6749
 * Dislikes: 307
 * Total Accepted:    659.9K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis1(int n) {
        int size = n << 1;
        vector<string> result;
        for (int i = 0; i < (1 << size); ++i) {
            check(i, size, result);
        }
        return result;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", 0, 0, n, result);
        return result;
    }

private: 
    void generate(string cur, int open, int close, int max, vector<string>& result) {
        if (cur.length() == 2 * max) {
            result.push_back(cur);
            return;
        } 
        if (open < max) 
            generate(cur + '(', open + 1, close, max, result);
        if (close < open)
            generate(cur + ')', open, close + 1, max, result);
    }
    
private:
    void check(int n, int size, vector<string>& result) {
        int balance = 0;
        string res(size, ')');
        int k = 0;
        for (int i = size - 1; i >= 0; --i) {
            if ((1 << i) & n) {
                ++balance;
                res[k] = '(';
            } else {
                if (balance) {
                    --balance;
                } else
                    return;
            }
            ++k;
        }
        if (!balance)
            result.push_back(res);
    }
};
// @lc code=end

