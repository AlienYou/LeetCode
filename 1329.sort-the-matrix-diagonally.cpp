/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (79.30%)
 * Likes:    819
 * Dislikes: 148
 * Total Accepted:    50.3K
 * Total Submissions: 61.5K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * A matrix diagonal is a diagonal line of cells starting from some cell in
 * either the topmost row or leftmost column and going in the bottom-right
 * direction until reaching the matrix's end. For example, the matrix diagonal
 * starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells
 * mat[2][0], mat[3][1], and mat[4][2].
 * 
 * Given an m x n matrix mat of integers, sort each matrix diagonal in
 * ascending order and return the resulting matrix.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * Output:
 * [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mymap;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mymap[i - j].push_back(mat[i][j]);
            }
        }
        
        for (int i = -n + 1; i < m; ++i) {
            sort(mymap[i].begin(), mymap[i].end());
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                mat[i][j] = mymap[i - j].back();
                mymap[i - j].pop_back();
            }
        }
        return mat;
    }
};
// @lc code=end

