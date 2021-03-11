/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (35.37%)
 * Likes:    3559
 * Dislikes: 642
 * Total Accepted:    471.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        int limit = min((matrix[0].size() - 1) / 2, (matrix.size() - 1) / 2); 
        for (int i = 0; i <= limit; ++i) {
            for (int curInd = left; curInd <= right; ++curInd) {
                res.push_back(matrix[top][curInd]);
            }
            ++top;
            for (int curInd = top; curInd <= bottom; ++curInd) {
                res.push_back(matrix[curInd][right]);
            }
            --right;
            for (int curInd = right; top <= bottom && curInd >= left; --curInd) {
                res.push_back(matrix[bottom][curInd]);
            }
            --bottom;
            for (int curInd = bottom; left <= right && curInd >= top; --curInd) {
                res.push_back(matrix[curInd][left]);
            }
            ++left;
        }
        return res;
    }
};
// @lc code=end

