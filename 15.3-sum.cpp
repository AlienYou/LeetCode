/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (27.68%)
 * Likes:    9462
 * Dislikes: 970
 * Total Accepted:    1.2M
 * Total Submissions: 4.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
            while (left < right) {
                if (nums[right] + nums[left] > -nums[i]) 
                    --right;
                else if (nums[left] + nums[right] < -nums[i])
                    ++left;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left + 1 < right && nums[left] == nums[left + 1]) ++left;
                    while (right - 1 > left && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};
// @lc code=end

