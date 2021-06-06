/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (45.97%)
 * Likes:    4713
 * Dislikes: 230
 * Total Accepted:    377.3K
 * Total Submissions: 815.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow up: Could you implement the O(n) solution?
 */

//如果没有限制时间复杂度，可通过排序后计算来解决
//O(n)的复杂度下，利用哈希表保存nums的元素
//遍历nums，判断当前元素是不是连续序列的首个数字，
//若是则，叠加遍历获得长度
//时间复杂度上，虽然有嵌套的while，但实际上这层嵌套循环不会由于!numSet.count的判断
//不会每次都执行

// @lc code=start
class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1;
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1])
                continue;
            if (nums[i] + 1 == nums[i + 1])
                ++cur;
            else {
                res = max(res, cur);
                cur = 1;
            } 
        }
        return max(res, cur);
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (const auto& ele : nums) {
            numSet.insert(ele);
        }
        int res = 0;
        for (const auto& ele : nums) {
            if (!numSet.count(ele - 1)) {
                int cur = ele;
                int curLen = 1;
                while (numSet.count(cur + 1)) {
                    cur++;
                    curLen++;
                }
                res = max(res, curLen);
            }
        }
        return res;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!numSet.count(nums[i] - 1)) {
                int curSeq = 1;
                int curEle = nums[i];
                while (numSet.count(curEle + 1)) {
                    curEle++;
                    curSeq++;
                }
                res = max(res, curSeq);
            }
        }
        return res;
    }
};
// @lc code=end

