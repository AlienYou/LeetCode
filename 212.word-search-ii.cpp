/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (36.39%)
 * Likes:    3509
 * Dislikes: 142
 * Total Accepted:    284.6K
 * Total Submissions: 764.2K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int wordLength = words.size();
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for (int l = 0; l < wordLength; ++l) {
            bool find = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == words[l][0] && DFS(board, i, j, m, n, 0, words[l])) {
                        res.push_back(words[l]);
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }
        }
        return res;
    }
    
    bool DFS(vector<vector<char>>& board, int r, int c, int rows, int cols, int ind, string& word) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[ind])
            return false;
        if (ind == word.length() - 1)
            return true;
        bool isExist = false;
        char orig = board[r][c];
        board[r][c] = '*';
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            isExist = isExist || DFS(board, nr, nc, rows, cols, ind + 1, word);
        }
        board[r][c] = orig;
        return isExist;
    }
};
// @lc code=end

