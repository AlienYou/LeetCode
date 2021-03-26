/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (42.24%)
 * Likes:    2009
 * Dislikes: 512
 * Total Accepted:    114.4K
 * Total Submissions: 262K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    public:
    static constexpr int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;        
        int rows = matrix.size();
        int cols = matrix[0].size();
        queue<pair<int, int>> parQueue;
        queue<pair<int, int>> atlQueue;
        for (int i = 0; i < rows; ++i) {
            parQueue.push({i, 0});
            atlQueue.push({i, cols - 1});
        }
        for (int i = 0; i < cols; ++i) {
            parQueue.push({0, i});
            atlQueue.push({rows - 1, i});
        }
        vector<vector<bool>> parVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlVisited(rows, vector<bool>(cols, false));
        bfs(matrix, parQueue, parVisited, rows, cols);
        bfs(matrix, atlQueue, atlVisited, rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (parVisited[i][j] && atlVisited[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& matrix, queue<pair<int, int>>& que, vector<vector<bool>>& visited, int rows, int cols) {
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int newRow = x + dir[i][0];
                int newCol = y + dir[i][1];
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol] || matrix[newRow][newCol] < matrix[x][y])
                    continue;
                que.push({newRow, newCol});
            }
        }
    }
};
// @lc code=end

