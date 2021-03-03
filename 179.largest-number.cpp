/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (30.34%)
 * Likes:    2830
 * Dislikes: 302
 * Total Accepted:    238.6K
 * Total Submissions: 778.1K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,2]
 * Output: "210"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1]
 * Output: "1"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [10]
 * Output: "10"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](string& s1, string& s2) {
            string&& L1 = s1 + s2;
            string&& L2 = s2 + s1; 
            return L1 > L2;
        };
        string result;
        vector<string> strs;
        for (const auto& ele : nums) {
           strs.push_back(to_string(ele));    
        }
        
        sort(strs.begin(), strs.end(), cmp);
        if (strs[0] == "0")
            return "0";
        for (const auto& s : strs)
            result += s;
        return result;
    } 
};
// @lc code=end

