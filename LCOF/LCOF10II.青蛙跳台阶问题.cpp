class Solution {
public:
    int numWays(int n) {
        const int mod = 1e9 + 7;
        int oneStep = 1;
        int twoStep = 1;
        for (int i = 2; i <= n; ++i) {
            int cur = (oneStep + twoStep) % mod;
            oneStep = twoStep;
            twoStep = cur;
        }
        return twoStep;
    }
};