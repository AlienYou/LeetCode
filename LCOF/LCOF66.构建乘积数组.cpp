class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int proRight = 1;
        vector<int> res(a.size(), 1);
        for (int i = 1; i < a.size(); ++i) {
            res[i] = res[i - 1] * a[i - 1];
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            res[i] *= proRight;
            proRight *= a[i];
        }
        return res;
    }
};