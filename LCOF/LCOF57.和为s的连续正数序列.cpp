class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> cur;
        int left = 1, right = 1, last = (target + 1) / 2;
        int sum = right;
        while (right <= last) {
            if (sum > target) {
                sum -= left;
                ++left;
            } else if (sum < target) {
                ++right;
                sum += right;
            } else {
                cur.clear();
                for (int i = left; i <= right; ++i)
                    cur.push_back(i);
                res.push_back(cur);
                ++right;
                sum += right;
            }
        }
        return res;
    }
};