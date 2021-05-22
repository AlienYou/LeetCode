/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (48.85%)
 * Likes:    3135
 * Dislikes: 109
 * Total Accepted:    262.3K
 * Total Submissions: 511.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

//关键：对角线与反对角线上的row - col或者row + col是相等的

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string curLevel;
        for (int i = 0; i < n; ++i) {
            curLevel.push_back('.');
        }
        vector<string> board(n, curLevel);
        
        unordered_set<int> cols;
        unordered_set<int> diagonal;
        unordered_set<int> antiDiagonal;
        
        backtrace(board, 0, n, cols, diagonal, antiDiagonal, res);
        return res;
    }
    
    void backtrace(vector<string>& board, int row, int n, unordered_set<int>& cols, unordered_set<int>& diagonal, unordered_set<int>& antiDiagonal, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            int dia = row - i;
            int antiDiag = row + i;
            if (cols.count(i) || diagonal.count(dia) || antiDiagonal.count(antiDiag))
                continue;
            board[row][i] = 'Q';
            cols.insert(i);
            diagonal.insert(dia);
            antiDiagonal.insert(antiDiag);
            
            backtrace(board, row + 1, n, cols, diagonal, antiDiagonal, res);
            
            cols.erase(i);
            diagonal.erase(dia);
            antiDiagonal.erase(antiDiag);
            board[row][i] = '.';
        }
    }
};
// @lc code=end

