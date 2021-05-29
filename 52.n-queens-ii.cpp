/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (59.56%)
 * Likes:    887
 * Dislikes: 186
 * Total Accepted:    166K
 * Total Submissions: 270.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
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

// @lc code=start
class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diagonal;
        unordered_set<int> antiDiagonal;
        DFS(0, n, cols, diagonal, antiDiagonal);
        return ans;
    }
    
    void DFS(int row, int n, unordered_set<int>& cols, unordered_set<int>& diagonal, unordered_set<int>& antiDiagonal) {
        if (row >= n) {
            ans++;
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            int dia = row - i;
            int antiDia = row + i;
            if (cols.count(i) || diagonal.count(dia) || antiDiagonal.count(antiDia))
                continue;
            cols.insert(i);
            diagonal.insert(dia);
            antiDiagonal.insert(antiDia);
            DFS(row + 1, n, cols, diagonal, antiDiagonal);
            
            cols.erase(i);
            diagonal.erase(dia);
            antiDiagonal.erase(antiDia);
        }
    }
};
// @lc code=end

