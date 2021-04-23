/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (45.35%)
 * Likes:    3004
 * Dislikes: 316
 * Total Accepted:    307.9K
 * Total Submissions: 658.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution {
public:
    int minimumTotal1(vector<vector<int>>& triangle) {
        int sum = INT_MAX;
        int rows = triangle.size();
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                int minV = INT_MAX;
                if (j > 0) 
                    minV = triangle[i - 1][j - 1];
                if (j < i)
                    minV = min(triangle[i - 1][j], minV);
                int path = minV + triangle[i][j];
                triangle[i][j] = path;
            }
        }
        
        for (int i = 0; i < triangle[rows - 1].size(); ++i)
            sum = min(sum, triangle[rows - 1][i]);
        return sum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> res(triangle[rows - 1].begin(), triangle[rows - 1].end());
        
        for (int i = rows - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};
// @lc code=end

