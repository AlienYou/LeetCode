/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (64.19%)
 * Likes:    3287
 * Dislikes: 110
 * Total Accepted:    253.5K
 * Total Submissions: 384.2K
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * The area of an island is the number of cells with a value 1 in the island.
 * 
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 * 
 * 
 */

//思路：思路不难，需要注意题意，不是求岛屿数目，而是求所有岛屿中的面积最大的值
//DFS，枚举四个方向即可
//这题应该也能用并查集做

// @lc code=start
class Solution {
public:
    static constexpr int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j, m, n));
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        grid[r][c] = 0;
        int ans = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) 
                ans += dfs(grid, nr, nc, rows, cols);
        }
        return ans;
    }
};
// @lc code=end

