/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.83%)
 * Likes:    4400
 * Dislikes: 6793
 * Total Accepted:    1.4M
 * Total Submissions: 5.5M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * Input: x = 123
 * Output: 321
 * Example 2:
 * Input: x = -123
 * Output: -321
 * Example 3:
 * Input: x = 120
 * Output: 21
 * Example 4:
 * Input: x = 0
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && last > 7)
                return 0;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && last < -8)
                return 0;
            res = res * 10 + last;
        }
        return res;
    }
};
// @lc code=end

