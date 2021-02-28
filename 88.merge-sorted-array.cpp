/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (40.14%)
 * Likes:    3209
 * Dislikes: 4856
 * Total Accepted:    772.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively. You may assume that nums1 has enough space (size that is equal
 * to m + n) to hold additional elements from nums2.
 * 
 * 
 * Example 1:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Example 2:
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n, m <= 200
 * 1 <= n + m <= 200
 * nums1.length == m + n
 * nums2.length == n
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sortIndex = nums1.size() - 1;
        while (n > 0) {
            if (m > 0 && nums1[m - 1] > nums2[n - 1])
            {
                nums1[sortIndex--] = nums1[m - 1];
                m--;
            }
            else {
                nums1[sortIndex--] = nums2[n - 1];
                n--;
            }
        }
    }
};
// @lc code=end

