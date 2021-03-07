/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    4043
 * Dislikes: 231
 * Total Accepted:    380.1K
 * Total Submissions: 776.2K
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 * 
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSquares1(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    } 
    
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }
        if (squares.back() == n)
            return 1;
        queue<int> que;
        for (int i = 0; i < squares.size(); ++i)
            que.push(squares[i]);
        int res = 1;
        while (!que.empty()) {
            int size = que.size();
            ++res;
            for (int i = 0; i < size; ++i) {
                int pre = que.front();
                que.pop();
                for (const auto& ele : squares) {
                    int cur = pre + ele;
                    if (cur == n)
                        return res;
                    else if (cur < n) {
                        que.push(cur);

                    }
                    else if (cur > n)
                        break;
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

