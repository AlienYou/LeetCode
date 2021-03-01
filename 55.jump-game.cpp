/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (35.03%)
 * Likes:    5804
 * Dislikes: 404
 * Total Accepted:    592.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    enum Index {
        GOOD, 
        BAD,
        UNKNOWN
    };
    vector<Index> memo;
    
    bool canJump1(vector<int>& nums) {
        memo.resize(nums.size(), UNKNOWN);
        memo[nums.size() - 1] = GOOD;
        return core(nums, 0);
    }
    
    bool core(vector<int>& nums, int curInd) {
        if (memo[curInd] != UNKNOWN) {
            return memo[curInd] == GOOD ? true : false;
        }
        int furthestJump = 0;
        if (curInd + nums[curInd] > nums.size() - 1)
            furthestJump = nums.size() - 1;
        else 
            furthestJump = curInd + nums[curInd];
        //int furthestJump = min(curInd + nums[curInd], nums.size() - 1);
        for (int next = curInd + 1; next <= furthestJump; ++next) {
            if (core(nums, next)) {
                memo[next] = GOOD;
                return true;
            }
        }
        memo[curInd] = BAD;
        return false;
    }
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size(), UNKNOWN);
        memo[nums.size() - 1] = GOOD;
        for (int i = nums.size() - 2; i >= 0; --i) {
            int fur = 0;
            if (i + nums[i] < nums.size() - 1)
                fur = i + nums[i];
            else 
                fur = nums.size() - 1;
            for (int j = i + 1; j <= fur; ++j) {
                if (memo[j] == GOOD) {
                    memo[i] = GOOD;
                    break;
                }
            }
        }
        return memo[0] == GOOD;
    }
};
// @lc code=end

