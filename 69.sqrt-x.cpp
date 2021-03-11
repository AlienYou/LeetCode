/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (34.75%)
 * Likes:    1852
 * Dislikes: 2256
 * Total Accepted:    687.4K
 * Total Submissions: 2M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, compute and return the square root of x.
 * 
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        int left = 1;
        int right = x, res;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                res = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        return res;
    }
};
// @lc code=end

