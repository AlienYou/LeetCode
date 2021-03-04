/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (59.76%)
 * Likes:    4616
 * Dislikes: 254
 * Total Accepted:    797.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */

// @lc code=start
class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0)
                candidate = nums[i];
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end

