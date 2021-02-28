/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (66.07%)
 * Likes:    1710
 * Dislikes: 117
 * Total Accepted:    113.8K
 * Total Submissions: 170.5K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.
 * 
 * Return a list of all possible strings we could create. You can return the
 * output in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "3z4"
 * Output: ["3z4","3Z4"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "12345"
 * Output: ["12345"]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "0"
 * Output: ["0"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        queue<string> que;
        que.push(S);
        for (int i = 0; i < S.length(); ++i) {
            if (isdigit(S[i]))
                continue;
            int size = que.size();
            for (int j = 0; j < size; ++j) {
                string s = que.front();
                que.pop();
                s[i] = toupper(s[i]);
                que.push(s);
                s[i] = tolower(s[i]);
                que.push(s);
            }
        }
        while (!que.empty()) { 
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
    
    vector<string> letterCasePermutation1(string S) {
        vector<string> result;
        helper(S, 0, result);
        return result;
    }
    
    void helper(string& s, int i, vector<string>& result) {
        if (i == s.length()) {
            result.push_back(s);
            return;
        }
        
        if (isdigit(s[i])) {
            helper(s, i + 1, result);
            return;
        }
        
        s[i] = toupper(s[i]);
        helper(s, i + 1, result);
        
        s[i] = tolower(s[i]);
        helper(s, i + 1, result);
    }
};
// @lc code=end

