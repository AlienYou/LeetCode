/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (50.61%)
 * Likes:    1589
 * Dislikes: 2637
 * Total Accepted:    216.3K
 * Total Submissions: 427.6K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 * 
 * 
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * -1000 <= a, b <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum1(int a, int b) {
        int res = 0;
        int bit = 0;
        for (int i = 0; i < 32; ++i) {
            int cur = 1 << i;
            if ((a & cur) & (b & cur)) {
                res |= bit << i;
                bit = 1;
            }
            else {
                res |= ((a & cur) | (b & cur)) ^ (bit << i);
                if (((a & cur) | (b & cur)) & (bit << i))
                    bit = 1;
                else 
                    bit = 0;
            }
        }
        return res;
    }
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);//负数测试不通过
    }
};
// @lc code=end

