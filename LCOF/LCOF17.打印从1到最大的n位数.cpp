class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int maxNum = 1;
        while (n) {
            maxNum *= 10;
            n--;
        }
        res.resize(maxNum - 1);
        for (int i = 1; i < maxNum; ++i) {
            res[i - 1] = i;
        }
        return res;
    }
};