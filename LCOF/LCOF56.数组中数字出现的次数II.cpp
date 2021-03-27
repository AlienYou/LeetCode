class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> res(32, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= 31; j++) {
                if ((1 << j) & nums[i])
                    res[j]++;
            }
        }
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            res[i] %= 3;
            ans = ans * 2 + res[i];
        }
        return ans;
    }
};