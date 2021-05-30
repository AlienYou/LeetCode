/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (36.54%)
 * Likes:    1258
 * Dislikes: 225
 * Total Accepted:    106.6K
 * Total Submissions: 280.8K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than two
 * elements, return 0.
 * 
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or
 * (6,9) has the maximum difference 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> count(10, 0);
        vector<int> temp(nums.size());
        int maxVal = *max_element(nums.begin(), nums.end());
        int exp = 1;
        while (maxVal >= exp) {
            for (int i = 0; i < count.size(); ++i)
                count[i] = 0;
            for (int i = 0; i < nums.size(); ++i)  {
                int cur = (nums[i] / exp) % 10;
                count[cur]++;
            }
            for (int i = 1; i < count.size(); ++i) {
                count[i] += count[i - 1];
            }
            
            for (int i = nums.size() - 1; i >= 0; --i) {
                int cur = (nums[i] / exp) % 10;
                temp[count[cur] - 1] = nums[i];
                count[cur]--;
            }
            copy(temp.begin(), temp.end(), nums.begin());
            exp *= 10;
        }
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
// @lc code=end

