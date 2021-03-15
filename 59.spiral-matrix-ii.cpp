/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    1572
 * Dislikes: 127
 * Total Accepted:    244.9K
 * Total Submissions: 422.4K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> ans(m + n, 0);
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int prod = n1 * n2;
                int cur = prod + ans[i + j + 1];
                ans[i + j + 1] = cur % 10;
                ans[i + j] += cur / 10;
            }
        }
        
        string res;
        int i = 0;
        for (; i < ans.size(); ++i) {
            if (ans[i] == 0 && res.size() == 0)
                continue;
            res.push_back(ans[i] + '0');
        }
        return res.size() == 0 ? "0" : res;
    }
};
// @lc code=end

