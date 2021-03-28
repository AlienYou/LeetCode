class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; ++i)
            dp[i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int sum = 6 * i; sum >= 1; --sum) {
                dp[sum] = 0;
                for (int j = 1; j <= 6; ++j) {
                    if (sum - j <= 0)
                        break;
                    dp[sum] += dp[sum - j];
                }
            }
        }
        vector<double> res;
        int all = pow(6, n);
        for (int i = n; i <= 6 * n; ++i) 
            res.push_back((double)dp[i] / all);
        return res;
    }
};