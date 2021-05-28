/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (49.07%)
 * Likes:    378
 * Dislikes: 8
 * Total Accepted:    21K
 * Total Submissions: 40.7K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        unordered_map<int, int> count;
        int ans = 0, sum = 0;
        while (right < nums.size()) {
            count[nums[right]]++;
            sum += nums[right];
            if (count[nums[right]] > 1) {
                while (left < right && count[nums[right]] > 1) {
                    sum -= nums[left];
                    count[nums[left]]--;
                    ++left;
                }
            }
            ans = max(ans, sum);
            ++right;
        }
        return ans;
    }
};
// @lc code=end

