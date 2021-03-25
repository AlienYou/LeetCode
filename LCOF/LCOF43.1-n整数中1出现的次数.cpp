class Solution {
public:
    int countDigitOne1(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += count(i);
        }
        return res;
    }
    int count(int n) {
        int c = 0;
        while (n) {
            if (n % 10 == 1)
                c++;
            n /= 10;
        }
        return c;
    }
    int countDigitOne(int n) {
        int res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        long digit = 1;
        while (high != 0 || cur != 0) {
            if (cur == 0) res += high * digit;
            else if (cur == 1) res += high * digit + low + 1;
            else if (cur > 1) res += (high + 1) * digit;
            low = cur * digit + low;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};