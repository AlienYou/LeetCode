class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        const int mod = 1e9 + 7;
        long res = 1;
        while (n > 4) {
            n -= 3;
            res *= 3; 
            res %= mod;
        }
        return (res * n) % mod;
    }
};