class Solution {
public:
    int cuttingRope1(int n) {
        int maxPro = 0;
        dfs(n, 1, 0, maxPro);
        return maxPro;
    }
    
    void dfs(int rest, int res, int count, int& maxPro) {
        if (count > 1 && rest == 0) {
            maxPro = max(maxPro, res);
            return ;
        }
        for (int i = 1; i <= rest; ++i) {
            dfs(rest - i, res * i, count + 1, maxPro);
        }
    }
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j <= 3; ++j) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};