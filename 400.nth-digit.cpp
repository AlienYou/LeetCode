/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (32.30%)
 * Likes:    456
 * Dislikes: 1209
 * Total Accepted:    65.4K
 * Total Submissions: 201.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the n^th digit of the infinite integer sequence
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 11
 * Output: 0
 * Explanation: The 11^th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 * 11, ... is a 0, which is part of the number 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        long start = 1;
        long count = 9;
        int digit = 1;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9 * digit * start;
        }
        int pos = start + (n - 1) / digit;
        int res = (n - 1) % digit;
        int ans = 0;
        while (digit != res) {
            ans = pos % 10;
            pos /= 10;
            --digit;
        }
        return ans;
    }
};
// @lc code=end

