/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (32.56%)
 * Likes:    6312
 * Dislikes: 205
 * Total Accepted:    450.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int maxPro = 1, minPro = 1;
        
        for (const auto& ele : nums) {
            if (ele < 0) 
                swap(maxPro, minPro);
            maxPro = max(maxPro * ele, ele);
            minPro = min(minPro * ele, ele);
            res = max(maxPro, res);
        }
        
        return res;
    }
    
    void print(vector<int>& v) {
        for (const auto& ele : v) {
            cout << ele << " ";
        } 
        cout << endl;
    }
};
// @lc code=end

