class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, m, n, 0, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int r, int c, int rows, int cols, int curInd, string& word) {
        if (board[r][c] != word[curInd])
            return false;
        if (curInd == word.length() - 1)
            return true;
        char orig = board[r][c];
        board[r][c] = '*';
        bool exist = false;
        for (int i = 0; i < 4 && exist; ++i) {
            int newR = r + dirs[i][0];
            int newC = c + dirs[i][1];
            if (newR >= 0 && newR < rows && newC >= 0 && newC < cols)
                exist = exist || dfs(board, newR, newC, rows, cols, curInd + 1, word);
        }
        board[r][c] = orig;
        return exist;
    }
};