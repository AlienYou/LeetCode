class UglyNumber{
private:
    vector<int> ugly;
public:
    UglyNumber() {
        ugly.resize(1690);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < 1690; ++i) {
            int u = min(min(ugly[i2] * 2, ugly[i3] * 3), ugly[i5] * 5);
            ugly[i] = u;
            if (u == ugly[i2] * 2) ++i2;
            if (u == ugly[i3] * 3) ++i3;
            if (u == ugly[i5] * 5) ++i5;
        }
    }
    int get(int n) {
        return ugly[n - 1];
    }
};
class Solution {
public:
    UglyNumber ugly;
    int nthUglyNumber(int n) {
        return ugly.get(n);
    }
};