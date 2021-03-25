class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = j == 0 ? dp[j] + grid[i][j] : max(dp[j], dp[j - 1]) + grid[i][j]; 
            }
        }
        return dp[n - 1];
    }
};