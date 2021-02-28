/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (38.31%)
 * Likes:    1189
 * Dislikes: 1350
 * Total Accepted:    245.8K
 * Total Submissions: 637.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Follow up: Could you write a solution that works in logarithmic time
 * complexity?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * 
 * Example 3:
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
 * 0 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0)
            return 0;
        return n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end

