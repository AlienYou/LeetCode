/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (33.35%)
 * Likes:    5244
 * Dislikes: 938
 * Total Accepted:    448.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, find the smallest missing positive
 * integer.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 300
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you implement an algorithm that runs in O(n) time and uses
 * constant extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i + 1 != A[i])
                return i + 1;
        }
        return n + 1;
    }
};
// @lc code=end

