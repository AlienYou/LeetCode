/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (22.12%)
 * Likes:    1073
 * Dislikes: 2181
 * Total Accepted:    145.4K
 * Total Submissions: 652.5K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * If multiple answers are possible, return any of them.
 * 
 * It is guaranteed that the length of the answer string is less than 10^4 for
 * all the given inputs.
 * 
 * 
 * Example 1:
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * Example 2:
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * Example 3:
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * Example 4:
 * Input: numerator = 4, denominator = 333
 * Output: "0.(012)"
 * Example 5:
 * Input: numerator = 1, denominator = 5
 * Output: "0.2"
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= numerator, denominator <= 2^31 - 1
 * denominator != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if (numerator == 0)
            return "0";
        unordered_map<int, int> set;
        string integ;
        integ = numerator < 0 == denominator < 0 ? "" : "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        long i = numerator / denominator;
        integ += to_string(i);
        string flo;
        long res = numerator;
        while (res = numerator % denominator) {
            numerator = res * 10;
            if (set.count(numerator)) {
                string floTemp;
                floTemp += flo.substr(0, set[numerator]) + '(' + flo.substr(set[numerator], flo.length() - set[numerator]) + ')';
                flo = floTemp;
                break;
            }
            set[numerator] = flo.length();
            flo += '0' + (numerator / denominator);
        }
        if (flo.length() > 0)
            integ += '.';
        return integ + flo;
    }
};
// @lc code=end

