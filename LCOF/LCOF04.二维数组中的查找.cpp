class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (matrix[x][y] == target)
                return true;
            if (matrix[x][y] > target)
                --y;
            else 
                ++x;
        }
        return false;
    }
};