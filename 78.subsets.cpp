/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (64.30%)
 * Likes:    5366
 * Dislikes: 108
 * Total Accepted:    731.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> vec;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) 
                    vec.push_back(nums[j]);
            }
            result.push_back(vec);
        }
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        core(nums, 0, res, cur);
        return res;
    }
    void core(vector<int>& nums, int pos, vector<vector<int>>& res, vector<int>& cur) {
        if (pos >= nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[pos]);
        core(nums, pos + 1, res, cur);
        cur.pop_back();
        core(nums, pos + 1, res, cur);
    }
};
// @lc code=end

