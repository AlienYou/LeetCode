/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (62.08%)
 * Likes:    1724
 * Dislikes: 57
 * Total Accepted:    55.2K
 * Total Submissions: 87.3K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 * 
 * 
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(())"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "(()(()))"
 * Output: 6
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses1(string S) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(')
                st.push(0);
            else {
                int inside = st.top();
                st.pop();
                int outside = st.top();
                st.pop();
                st.push(outside + max(2 * inside, 1));
            }
        }
        return st.top();
    }
    int scoreOfParentheses(string S) {
        int ans = 0, pare = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(')
                ++pare;
            else {
                --pare;
                if (S[i - 1] == '(')
                    ans += 1 << pare;
            }
        }
        return ans;
    }
};
// @lc code=end

