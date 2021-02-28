/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 *
 * https://leetcode.com/problems/minimize-deviation-in-array/description/
 *
 * algorithms
 * Hard (44.78%)
 * Likes:    385
 * Dislikes: 18
 * Total Accepted:    15.2K
 * Total Submissions: 31.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given an array nums of n positive integers.
 * 
 * You can perform two types of operations on any element of the array any
 * number of times:
 * 
 * 
 * If the element is even, divide it by 2.
 * 
 * 
 * For example, if the array is [1,2,3,4], then you can do this operation on
 * the last element, and the array will be [1,2,3,2].
 * 
 * 
 * If the element is odd, multiply it by 2.
 * 
 * For example, if the array is [1,2,3,4], then you can do this operation on
 * the first element, and the array will be [2,2,3,4].
 * 
 * 
 * 
 * 
 * The deviation of the array is the maximum difference between any two
 * elements in the array.
 * 
 * Return the minimum deviation the array can have after performing some number
 * of operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 1
 * Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2],
 * then the deviation will be 3 - 2 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,1,5,20,3]
 * Output: 3
 * Explanation: You can transform the array after two operations to
 * [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,10,8]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 2 <= n <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mi = INT_MAX;
        priority_queue<int> que;
        for (auto& i : nums) {
            if (i & 1) {
                i = i << 1;
            }
            mi = min(i, mi);
            que.push(i);
        }
        int result = INT_MAX;
        while (que.top() % 2 == 0) {
            int cur = que.top();
            que.pop();
            result = min(result, cur - mi);
            cur >>= 1;
            mi = min(cur, mi);
            que.push(cur);
        }
        return min(result, que.top() - mi);
    }
};
// @lc code=end

