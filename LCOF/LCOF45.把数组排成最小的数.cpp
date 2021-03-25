class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> res;
        for (auto& e : nums)
            res.push_back(to_string(e));
        auto cmp = [](const string& s1, const string& s2) { return s1 + s2 < s2 + s1; };
        sort(res.begin(), res.end(), cmp);
        string ans;
        for (auto &ss : res)
            ans += ss;
        return ans;
    }

    string minNumber1(vector<int>& nums) {
        string res, cur;
        dfs(nums, 0, res, cur);
        return res;
    }
    void dfs(vector<int>& nums, int ind, string& res, string cur) {
        if (ind == nums.size()) { 
            if (res == "" || res > cur)
                res = cur;
            return;
        }
        for (int i = ind; i < nums.size(); ++i) {
            swap(nums[i], nums[ind]);
            dfs(nums, ind + 1, res, cur + to_string(nums[ind]));
            swap(nums[i], nums[ind]);
        }
    }
};