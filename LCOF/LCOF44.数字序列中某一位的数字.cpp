class Solution {
public:
    int findNthDigit(int n) {
        long start = 1;
        long count = 9;
        int digit = 1;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9 * digit * start;
        }
        int pos = start + (n - 1) / digit;
        int res = (n - 1) % digit;
        int ans = 0;
        while (digit != res) {
            ans = pos % 10;
            pos /= 10;
            --digit;
        }
        return ans;
    }
};