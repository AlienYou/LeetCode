/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (44.26%)
 * Likes:    2779
 * Dislikes: 52
 * Total Accepted:    194.9K
 * Total Submissions: 433.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 * 
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> memo(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j, m, n, memo));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int row, int col, int m, int n, vector<vector<int>>& memo) {
        if (memo[row][col] != 0)
            return memo[row][col];
        ++memo[row][col];
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col])
                memo[row][col] = max(memo[row][col], 1 + dfs(matrix, newRow, newCol, m, n, memo));
        }
        return memo[row][col];
    }
};
// @lc code=end

