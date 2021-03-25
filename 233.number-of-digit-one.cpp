/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (31.63%)
 * Likes:    383
 * Dislikes: 725
 * Total Accepted:    52.6K
 * Total Submissions: 165.3K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 13
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 2 * 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countDigitOne1(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += count(i);
        }
        return res;
    }
    int count(int n) {
        int c = 0;
        while (n) {
            if (n % 10 == 1)
                c++;
            n /= 10;
        }
        return c;
    }
    int countDigitOne(int n) {
        int res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        long digit = 1;
        while (high != 0 || cur != 0) {
            if (cur == 0) res += high * digit;
            else if (cur == 1) res += high * digit + low + 1;
            else if (cur > 1) res += (high + 1) * digit;
            low = cur * digit + low;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
// @lc code=end

