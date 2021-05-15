/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (15.68%)
 * Likes:    38
 * Dislikes: 92
 * Total Accepted:    205.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"0"'
 *
 * A valid number can be split up into these components (in order):
 * 
 * 
 * A decimal number or an integer.
 * (Optional) An 'e' or 'E', followed by an integer.
 * 
 * 
 * A decimal number can be split up into these components (in order):
 * 
 * 
 * (Optional) A sign character (either '+' or '-').
 * One of the following formats:
 * 
 * At least one digit, followed by a dot '.'.
 * At least one digit, followed by a dot '.', followed by at least one
 * digit.
 * A dot '.', followed by at least one digit.
 * 
 * 
 * 
 * 
 * An integer can be split up into these components (in order):
 * 
 * 
 * (Optional) A sign character (either '+' or '-').
 * At least one digit.
 * 
 * 
 * For example, all the following are valid numbers: ["2", "0089", "-0.1",
 * "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93",
 * "-123.456e789"], while the following are not valid numbers: ["abc", "1a",
 * "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 * 
 * Given a string s, return true if s is a valid number.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "0"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "e"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "."
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = ".1"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * s consists of only English letters (both uppercase and lowercase), digits
 * (0-9), plus '+', minus '-', or dot '.'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    enum STATE{
        INIT_STATE,
        SIGN_STATE,
        NUM_STATE,
        POINT_STATE,
        POINT_NUM_STATE,
        EXP_STATE,
        EXP_SIGN_STATE,
        EXP_NUM_STATE,
        POINT_WITHOUT_INT_STATE,
        END_STATE,
    };
    enum CHAR_TYPE {
        CHAR_SIGN,
        CHAR_POINT,
        CHAR_NUM,
        CHAR_EXP,
        CHAR_INVALID
    };
    
    CHAR_TYPE getType(char c) {
        if (c == '.')
            return CHAR_POINT;
        else if (c == '+' || c == '-')
            return CHAR_SIGN;
        else if (c >= '0' && c <= '9')
            return CHAR_NUM;
        else if (c == 'e' || c == 'E')
            return CHAR_EXP;
        return CHAR_INVALID;
    }
    
    unordered_map<STATE, unordered_map<CHAR_TYPE, STATE>> stChange = {
        {INIT_STATE, {{CHAR_SIGN, SIGN_STATE},
                      {CHAR_NUM, NUM_STATE},
                      {CHAR_POINT, POINT_WITHOUT_INT_STATE}}},
        {SIGN_STATE, {{CHAR_NUM, NUM_STATE},
                      {CHAR_POINT, POINT_WITHOUT_INT_STATE}}},
        {NUM_STATE, {{CHAR_POINT, POINT_STATE},
                     {CHAR_NUM, NUM_STATE},
                     {CHAR_EXP, EXP_STATE}}},
        {POINT_STATE, {{CHAR_NUM, POINT_NUM_STATE},
                       {CHAR_EXP, EXP_STATE}}},
        {POINT_WITHOUT_INT_STATE, {{CHAR_NUM, POINT_NUM_STATE}}},
        {POINT_NUM_STATE, {{CHAR_NUM, POINT_NUM_STATE},
                           {CHAR_EXP, EXP_STATE}}},
        {EXP_STATE, {{CHAR_SIGN, EXP_SIGN_STATE},
                     {CHAR_NUM, EXP_NUM_STATE}}},
        {EXP_SIGN_STATE, {{CHAR_NUM, EXP_NUM_STATE}}},
        {EXP_NUM_STATE, {{CHAR_NUM, EXP_NUM_STATE}}}
    };
    
    bool isNumber(string s) {
        STATE curSt = INIT_STATE;
        for (int i = 0; i < s.length(); ++i) {
            CHAR_TYPE curType = getType(s[i]);
            if (stChange[curSt].find(curType) == stChange[curSt].end())
                return false;
            curSt = stChange[curSt][curType];
        }
        return curSt == NUM_STATE || curSt == POINT_STATE || curSt == POINT_NUM_STATE || curSt == EXP_NUM_STATE;
    }
};
// @lc code=end

