class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        const int mod = 1e9 + 7;
        int first = 0;
        int second = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = (second + first) % mod;
            first = second;
            second = temp;
        }
        
        return second;
    }
};