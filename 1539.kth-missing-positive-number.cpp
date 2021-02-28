/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 *
 * https://leetcode.com/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (53.36%)
 * Likes:    748
 * Dislikes: 30
 * Total Accepted:    61.7K
 * Total Submissions: 111.9K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * Given an array arr of positive integers sorted in a strictly increasing
 * order, and an integer k.
 * 
 * Find the k^th positive integer that is missing from this array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The
 * 5^th missing positive integer is 9.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2^nd missing
 * positive integer is 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * arr[i] < arr[j] for 1 <= i < j <= arr.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthPositive1(vector<int>& arr, int k) {
        vector<bool> v(1001, false);
        for (int i = 0; i < arr.size(); ++i) {
            v[arr[i]] = true;
        }
        int count = 0;
        int i = 1;
        while (true) {
            if (i > 1000 || !v[i])
                ++count;
            if (count == k)
                break;
            ++i;
        }
        return i;
    }
    int findKthPositive2(vector<int>& arr, int k) {
        int i = 1;
        for (; i < arr.size(); ++i) {
            if (arr[i] - i - 1 >= k) {
                break;
            }
        }
        return k + i;
    }
   
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] - mid - 1 >= k)
                right = mid;
            else 
                left = mid + 1;
        }
        return k + left;
    }
};
// @lc code=end

