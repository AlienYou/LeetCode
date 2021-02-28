/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 *
 * https://leetcode.com/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (52.11%)
 * Likes:    365
 * Dislikes: 15
 * Total Accepted:    34.2K
 * Total Submissions: 63.2K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * You are given an integer array nums and an integer k.
 * 
 * In one operation, you can pick two numbers from the array whose sum equals k
 * and remove them from the array.
 * 
 * Return the maximum number of operations you can perform on the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 5
 * Output: 2
 * Explanation: Starting with nums = [1,2,3,4]:
 * - Remove numbers 1 and 4, then nums = [2,3]
 * - Remove numbers 2 and 3, then nums = []
 * There are no more pairs that sum up to 5, hence a total of 2 operations.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,1,3,4,3], k = 6
 * Output: 1
 * Explanation: Starting with nums = [3,1,3,4,3]:
 * - Remove the first two 3's, then nums = [1,4,3]
 * There are no more pairs that sum up to 6, hence a total of 1 operation.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxOperations1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int result = 0;
        while (left < right) {
            if (nums[left] + nums[right] < k) 
                left++;
            else if (nums[left] + nums[right] > k)
                right--;
            else {
                result++;
                left++;
                right--;
            }
        }
        return result;
    }
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for (auto& ele : nums) mymap[ele]++;
        
        int result = 0;
        for (auto mt = mymap.begin(); mt != mymap.end(); ++mt) {
            int num = mt->first, count = mt->second;
            if (k - num == num) result += count / 2;
            else if (mymap.count(k - num)) {
                int n = min(count, mymap[k - num]);
                result += n;
                mymap[num] -= n;
                mymap[k - num] -= n;
            }
        }
        return result;
    }
};
// @lc code=end

