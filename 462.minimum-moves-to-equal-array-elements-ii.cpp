/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (54.26%)
 * Likes:    811
 * Dislikes: 57
 * Total Accepted:    61.1K
 * Total Submissions: 110.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 * 
 * In one move, you can increment or decrement an element of the array by 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,10,2,9]
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = rand() % (right - left + 1) + left;
        swap(nums[right], nums[pivot]);
        int small = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] < nums[right]) {
                swap(nums[i], nums[small]);
                small++;
            }
        }
        swap(nums[small], nums[right]);
        return small;
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int index) {
        if (left == right)
            return nums[left];
        int k = partition(nums, left, right);
        if (k == index)
            return nums[k];
        else if (k < index) 
            return quickSelect(nums, k + 1, right, index);
        else 
            return quickSelect(nums, left, k - 1, index);
    }
    
    int minMoves2(vector<int>& nums) {
        int median = quickSelect(nums, 0, nums.size() - 1, nums.size() >> 1);
        int ans = 0;
        //cout << median << endl;
        for (int i = 0; i < nums.size(); ++i) {
            ans += abs(nums[i] - median);
        }
        return ans;
    }
    
    int minMoves2_1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, count = 0;
        while (left < right) {
            count += nums[right--] - nums[left++];
        }
        return count;
    }
};
// @lc code=end

