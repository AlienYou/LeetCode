/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 *
 * https://leetcode.com/problems/find-the-most-competitive-subsequence/description/
 *
 * algorithms
 * Medium (37.80%)
 * Likes:    651
 * Dislikes: 41
 * Total Accepted:    27.3K
 * Total Submissions: 60.4K
 * Testcase Example:  '[3,5,2,6]\n2'
 *
 * Given an integer array nums and a positive integer k, return the most
 * competitive subsequence of nums of size k.
 * 
 * An array's subsequence is a resulting sequence obtained by erasing some
 * (possibly zero) elements from the array.
 * 
 * We define that a subsequence a is more competitive than a subsequence b (of
 * the same length) if in the first position where a and b differ, subsequence
 * a has a number less than the corresponding number in b. For example, [1,3,4]
 * is more competitive than [1,3,5] because the first position they differ is
 * at the final number, and 4 is less than 5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,5,2,6], k = 2
 * Output: [2,6]
 * Explanation: Among the set of every possible subsequence: {[3,5], [3,2],
 * [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,3,3,5,4,9,6], k = 4
 * Output: [2,3,3,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> mostCompetitive1(vector<int>& nums, int k) {
        vector<int> result(k, INT_MAX);
        vector<int> curV;
        core(nums, curV, result, k, 0);
        return result;
    }
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            while (result.size() && result.back() > nums[i] && result.size() - 1 + nums.size() - i >= k)
                result.pop_back();
            if (result.size() < k)
                result.push_back(nums[i]);
        }
        return result;
    }
    
    void core(vector<int>& nums, vector<int>& curV, vector<int>& result, int k, int index) {
        if (curV.size() == k) {
            for (int i = 0; i < k; ++i) {
                if (result[i] > curV[i]) {
                    copy(curV.begin(), curV.end(), result.begin());
                    break;
                }
            }
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            curV.push_back(nums[i]);
            core(nums, curV, result, k, i + 1);
            curV.pop_back();
        }
    }
    }
};
// @lc code=end

