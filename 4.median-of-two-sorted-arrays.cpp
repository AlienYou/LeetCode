/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (30.68%)
 * Likes:    9330
 * Dislikes: 1442
 * Total Accepted:    874K
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 * 
 * Follow up: The overall run time complexity should be O(log (m+n)).
 */

class MedianPriorityQueue{
public:
    void push(int val) {
        maxHeap.push(val);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }   
    
    double getMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return double(maxHeap.top() + minHeap.top()) / 2; 
    }
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        MedianPriorityQueue mpq;
        for (const auto& ele : nums1) {
            mpq.push(ele);            
        }
        for (const auto& ele : nums2) {
            mpq.push(ele);
        }
        return mpq.getMedian();
    }
};
// @lc code=end

