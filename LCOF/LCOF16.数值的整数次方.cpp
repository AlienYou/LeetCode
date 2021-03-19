class Solution {
public:
    double myPow1(double x, int n) {
        long N = n;
        if (n < 0)
            N = -N;
        double res = 1;
        while (N) {
            if (N & 1) res *= x;
            x *= x;
            N >>= 1;
        }
        return n < 0 ? 1 / res : res;
    }

    double myPow(double x, int n) {
        long N = n;
        return n < 0 ? 1.0 / pow(x, -N) : pow(x, N);
    }
    double pow(double x, long n) {
        if (n == 0)
            return 1.0;
        double curP = myPow(x , n >> 1);
        curP *= curP;
        if (n & 1)
            curP *= x;
        return curP;
    }
};