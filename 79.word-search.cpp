/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.49%)
 * Likes:    5323
 * Dislikes: 235
 * Total Accepted:    624.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * Note: There will be some test cases with a board or a word larger than
 * constraints to test if your solution is using pruning.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0)
            return true;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && exist(board, i, j, m, n, 0, word))
                    return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, int r, int c, int rows, int cols, int ind, string& word) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[ind]) 
            return false;
        if (ind >= word.length() - 1)
            return true;
        bool isExist = false;
        char orig = board[r][c];
        board[r][c] = '*';
        for (int i = 0; i < 4; ++i) {
            int newR = r + dirs[i][0];
            int newC = c + dirs[i][1];
            isExist = isExist || exist(board, newR, newC, rows, cols, ind + 1, word);
        }
        board[r][c] = orig;
        return isExist;
    }
};
// @lc code=end

