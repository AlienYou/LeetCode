/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (51.87%)
 * Likes:    2045
 * Dislikes: 506
 * Total Accepted:    466.3K
 * Total Submissions: 897.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums1.size(); ++i) {
            numMap[nums1[i]]++;
        }
        
        for (const auto& ele : nums2) {
            if (numMap.count(ele) && numMap[ele] > 0) {
                numMap[ele]--;
                result.push_back(ele);
            }
        }
        
        return result;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> result;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else 
                ++i;
        }
        return result;
    }
};
// @lc code=end

