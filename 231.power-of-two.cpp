/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (43.79%)
 * Likes:    1256
 * Dislikes: 215
 * Total Accepted:    403.6K
 * Total Submissions: 921K
 * Testcase Example:  '1'
 *
 * Given an integer n, return true if it is a power of two. Otherwise, return
 * false.
 * 
 * An integer n is a power of two, if there exists an integer x such that n ==
 * 2^x.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: true
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 4
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 5
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo1(int n) {
        if (n <= 0)
            return false;
        while (n != 1) {
            if (n % 2)
                return false;
            n /= 2;
        }
        return true;
    }
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};
// @lc code=end

