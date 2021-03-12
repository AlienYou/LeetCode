/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (29.08%)
 * Likes:    2564
 * Dislikes: 756
 * Total Accepted:    287.4K
 * Total Submissions: 973.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that
 * is not on the border and it is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["X"]]
 * Output: [["X"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int j = 0; j < rows; ++j) {
            dfs(board, j, 0, rows, cols);
            dfs(board, j, cols - 1, rows, cols);
        }
        for (int j = 1; j < cols - 1; ++j) {
            dfs(board, 0, j, rows, cols);
            dfs(board, rows - 1, j ,rows, cols);
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == '-')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int row, int col, int rows, int cols) {
        if (col < 0 || col >= cols || row < 0 || row >= rows || board[row][col] != 'O') 
            return;
        board[row][col] = '-';
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            dfs(board, newRow, newCol, rows, cols);
        }
    }
};
// @lc code=end

