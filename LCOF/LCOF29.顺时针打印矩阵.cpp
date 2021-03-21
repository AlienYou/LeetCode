class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return vector<int>();
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottum = m - 1;
        int limit = (min(m, n) + 1) / 2;
        vector<int> res;
        for (int i = 0; i < limit; ++i) {
            for (int ind = left; ind <= right; ++ind) res.push_back(matrix[top][ind]);
            ++top;
            for (int ind = top; ind <= bottum; ++ind) res.push_back(matrix[ind][right]);
            --right;
            for (int ind = right; top <= bottum && ind >= left; --ind) res.push_back(matrix[bottum][ind]);
            --bottum;
            for (int ind = bottum; left <= right && ind >= top; --ind) res.push_back(matrix[ind][left]);
            ++left;
        }
        return res;
    }
};