/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (38.95%)
 * Likes:    917
 * Dislikes: 65
 * Total Accepted:    65.3K
 * Total Submissions: 164.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In an N by N square grid, each cell is either empty (0) or blocked (1).
 * 
 * A clear path from top-left to bottom-right has length k if and only if it is
 * composed of cells C_1, C_2, ..., C_k such that:
 * 
 * 
 * Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
 * different and share an edge or corner)
 * C_1 is at location (0, 0) (ie. has value grid[0][0])
 * C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
 * If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] ==
 * 0).
 * 
 * 
 * Return the length of the shortest such clear path from top-left to
 * bottom-right.  If such a path does not exist, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,0,0],[1,1,0],[1,1,0]]
 * 
 * 
 * Output: 4
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[r][c] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0][0])
            return -1;
        if (grid.size() == 1 && grid[0].size() == 1 && !grid[0][0])
            return 1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dir = { 
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };
        int result = 0;
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));
        while (!que.empty()) {
            int size = que.size();
            result++;
            for (int i = 0; i < size; ++i) {
                auto cur = que.front();
                que.pop();
                for (int d = 0; d < dir.size(); ++d) {
                    int newRow = cur.first + dir[d][0];
                    int newCol = cur.second + dir[d][1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !grid[newRow][newCol]) {
                        que.push(make_pair(newRow, newCol));
                        grid[newRow][newCol] = 1;
                        if (newRow == rows - 1 && newCol == cols - 1)
                            return ++result;
                    }
                }
            }
        }
        return -1;
    }
    }
};
// @lc code=end

