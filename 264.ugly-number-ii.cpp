/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (42.69%)
 * Likes:    2505
 * Dislikes: 156
 * Total Accepted:    202.4K
 * Total Submissions: 471.4K
 * Testcase Example:  '10'
 *
 * Given an integer n, return the n^th ugly number.
 * 
 * Ugly number is a positive number whose prime factors only include 2, 3,
 * and/or 5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * Explanation: 1 is typically treated as an ugly number.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1690
 * 
 * 
 */

// @lc code=start
class UglyNumber{
private:
    vector<int> ugly;
public:
    UglyNumber() {
        ugly.resize(1690);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < 1690; ++i) {
            int u = min(min(ugly[i2] * 2, ugly[i3] * 3), ugly[i5] * 5);
            ugly[i] = u;
            if (u == ugly[i2] * 2) ++i2;
            if (u == ugly[i3] * 3) ++i3;
            if (u == ugly[i5] * 5) ++i5;
        }
    }
    int get(int n) {
        return ugly[n - 1];
    }
};
class Solution {
public:
    UglyNumber ugly;
    int nthUglyNumber(int n) {
        return ugly.get(n);
    }
};
// @lc code=end

