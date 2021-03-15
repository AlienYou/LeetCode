/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.68%)
 * Likes:    2329
 * Dislikes: 964
 * Total Accepted:    354.6K
 * Total Submissions: 1M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 * 
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
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

