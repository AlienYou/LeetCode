/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (42.43%)
 * Likes:    857
 * Dislikes: 359
 * Total Accepted:    89.7K
 * Total Submissions: 211.5K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 * 
 * You are given an integer array nums representing the data status of this set
 * after the error.
 * 
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums1(vector<int>& nums) {
        vector<bool> check(nums.size() + 1, true);
        int dup = 0, loss = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!check[nums[i]])
                dup = nums[i];
            else
                check[nums[i]] = !check[nums[i]];
        }
        for (int i = 1; i < check.size(); ++i) {
            if (check[i]) {
                loss = i;
                break;
            }
        }
        return {dup, loss};
    }
    vector<int> findErrorNums(vector<int>& nums) {
        int xorA = 0, xor1 = 0, xor2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xorA ^= nums[i];
        }
        
        for (int i = 1; i <= nums.size(); ++i) {
            xorA ^= i;
        }
        
        int rightmostBit = xorA & (-xorA);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & rightmostBit) 
                xor1 ^= nums[i];
            else 
                xor2 ^= nums[i];
        }
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (i & rightmostBit)
                xor1 ^= i;
            else 
                xor2 ^= i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == xor1)
                return {xor1, xor2};
        }
        return {xor2, xor1};
    }
};
// @lc code=end

