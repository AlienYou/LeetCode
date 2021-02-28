/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    6856
 * Dislikes: 738
 * Total Accepted:    471.1K
 * Total Submissions: 818.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 * 
 * There is only one repeated number in nums, return this repeated number.
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * Example 3:
 * Input: nums = [1,1]
 * Output: 1
 * Example 4:
 * Input: nums = [1,1,2]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n^2)?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(nums[i]))
                return nums[i];
            set.insert(nums[i]);
        }
        return 0;
    }
    
    int findDuplicate(vector<int>& nums) {
        int right = nums.size();
        int left = 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                count += nums[i] <= mid;
            }
            if (count <= mid)
                left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

