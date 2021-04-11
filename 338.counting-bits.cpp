/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (70.17%)
 * Likes:    3763
 * Dislikes: 207
 * Total Accepted:    347.3K
 * Total Submissions: 492K
 * Testcase Example:  '2'
 *
 * Given an integer num, return an array of the number of 1's in the binary
 * representation of every number in the range [0, num].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time O(32n). Can you do
 * it in linear time O(n) and possibly in a single pass?
 * Could you solve it in O(n) space complexity?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> res;
        for (int i = 0; i <= num; ++i)
            res.emplace_back(getOnes(i));
        return res;
    }
    int getOnes(int num) {
        int sum = 0;
        while (num) {
            num = num & (num - 1);
            sum++;
        }
        return sum;
    }
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        if (num == 0)
            return dp;
        dp[1] = 1;
        for (int i = 2; i <= num; ++i) {
            if (i & 1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i >> 1];
        }
        return dp;
    }
};
// @lc code=end

