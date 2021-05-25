/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (37.48%)
 * Likes:    1445
 * Dislikes: 508
 * Total Accepted:    268.6K
 * Total Submissions: 709.5K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int evalRPN1(vector<string>& tokens) {
        vector<int> st;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-"){
                int curNum1 = st.back();
                st.pop_back();
                int curNum2 = st.back();
                st.pop_back();
                st.push_back(getResult(tokens[i], curNum2, curNum1));
            } else
                st.push_back(atoi(tokens[i].c_str()));
        }
        return st[0];
    }

    int getResult(string& notation, int curNum1, int curNum2) {
        if (notation == "/")
            return curNum1 / curNum2;
        else if (notation == "*")
            return curNum1 * curNum2;
        else if (notation == "-")
            return curNum1 - curNum2;
        return curNum1 + curNum2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> numSt;
        for (int i = 0; i < tokens.size(); ++i) {
            if(isNum(tokens[i])) {
                numSt.push(to_int(tokens[i]));
            } else {
                    int b = numSt.top();
                    numSt.pop();
                    int a = numSt.top();
                    numSt.pop();
                    numSt.push(cal(a, b, tokens[i]));
                }
            } 
        return numSt.top();
    }
    
    bool isNum(const string& s) {
        if (s.size() == 1 && (s[0] == '-' || s[0] == '+' || s[0] == '*' || s[0] == '/'))
            return false;
        return true;
    }
    
    int cal(int a, int b, string token) {
        if (token == "+")
            return a + b;
        else if (token == "-")
            return a - b;
        else if (token == "/")
            return a / b;
        else if (token == "*")
            return a * b;
        return 0;
    }
    
    int to_int(string s) {
        int sum = 0;
        int sign = 1;
        
        for (const auto& ele : s) {
            if (ele == '-') 
                sign = -1;
            else
                sum = sum * 10 + (ele - '0');
        }
        return sign * sum;
    }
};
// @lc code=end

