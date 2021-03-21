/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (54.08%)
 * Likes:    332
 * Dislikes: 113
 * Total Accepted:    23.3K
 * Total Submissions: 40.2K
 * Testcase Example:  '1'
 *
 * Starting with a positive integer N, we reorder the digits in any order
 * (including the original order) such that the leading digit is not zero.
 * 
 * Return true if and only if we can do this in a way such that the resulting
 * number is a power of 2.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 24
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 46
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int v1[10];
        int v2[10];
        memset(v1, 0, sizeof(v1));
        memset(v2, 0, sizeof(v2));
        count(N, v1);
        for (int i = 0; i < 31; ++i) {
            memset(v2, 0, sizeof(v2));
            count(1 << i, v2);
            if (sameDigits(v1, v2, 10))
                return true;
        }
        return false;
    }
    
    void count(int N, int* v2) {
        while (N) {
            v2[N % 10]++;
            N /= 10;
        }
    }
    
    bool sameDigits(int* v1, int* v2, int n) {
        for (int i = 0; i < n; ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

