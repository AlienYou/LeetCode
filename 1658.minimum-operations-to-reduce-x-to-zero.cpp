/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (30.45%)
 * Likes:    345
 * Dislikes: 7
 * Total Accepted:    9.9K
 * Total Submissions: 32.1K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * You are given an integer array nums and an integer x. In one operation, you
 * can either remove the leftmost or the rightmost element from the array nums
 * and subtract its value from x. Note that this modifies the array for future
 * operations.
 * 
 * Return the minimum number of operations to reduce x to exactly 0 if it's
 * possible, otherwise, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,4,2,3], x = 5
 * Output: 2
 * Explanation: The optimal solution is to remove the last two elements to
 * reduce x to zero.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,6,7,8,9], x = 4
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,2,20,1,1,3], x = 10
 * Output: 5
 * Explanation: The optimal solution is to remove the last three elements and
 * the first two elements (5 operations in total) to reduce x to zero.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
 * 
 */

// @lc code=start
class Solution {
public:
    int minOperations1(vector<int>& nums, int x) {
        int target = -x;
        for (auto ele : nums) {
            target += ele;
        }
        if (target == 0) return nums.size();
        int result = -1;
        unordered_map<int, int> mymap;
        mymap[0] = -1;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (mymap.count(sum - target)) {
                result = max(result, i - mymap[sum - target]);
            }
            mymap[sum] = i;
        }
        return result == -1? result : n - result;
    }
    int minOperations(vector<int>& nums, int x) {
        int result = -1;
        int sum = 0;
        for (auto& ele: nums) {
            sum += ele;
        }
        int currentSum = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (right < nums.size()) {
                currentSum += nums[right++];
            }
            while (currentSum > sum - x && left < nums.size()) {
                currentSum -= nums[left++];
            }
            if (currentSum == sum - x) {
                result = max(result, right - left);
            }
        }
        return result == -1 ? result : nums.size() - result;
    }
};
// @lc code=end

