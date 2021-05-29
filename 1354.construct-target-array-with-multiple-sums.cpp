/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 *
 * https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
 *
 * algorithms
 * Hard (31.39%)
 * Likes:    547
 * Dislikes: 68
 * Total Accepted:    22.8K
 * Total Submissions: 72.6K
 * Testcase Example:  '[9,3,5]'
 *
 * You are given an array target of n integers. From a starting array arr
 * consisting of n 1's, you may perform the following procedure :
 * 
 * 
 * let x be the sum of all elements currently in your array.
 * choose index i, such that 0 <= i < n and set the value of arr at index i to
 * x.
 * You may repeat this procedure as many times as needed.
 * 
 * 
 * Return true if it is possible to construct the target array from arr,
 * otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = [9,3,5]
 * Output: true
 * Explanation: Start with arr = [1, 1, 1] 
 * [1, 1, 1], sum = 3 choose index 1
 * [1, 3, 1], sum = 5 choose index 2
 * [1, 3, 5], sum = 9 choose index 0
 * [9, 3, 5] Done
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = [1,1,1,2]
 * Output: false
 * Explanation: Impossible to create target array from [1,1,1,1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = [8,5]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == target.length
 * 1 <= n <= 5 * 10^4
 * 1 <= target[i] <= 10^9
 * 
 * 
 */

//逆向思考：考虑从当前数组回溯到原始[1,1,...1]数组
//[9,3,5]，由于数组每个元素都是大于0，因此经过数组和每次替换后的数字一定是数组的最大值
//考虑用优先级队列维护当前数组的最大值
//根据当前数组和total和当前数组最大值curMax可得到等式
//r = total - curMax
//curMax = lastMax + r
//last = curMax - r,由于可能last仍大于r,(参考[10000,1]),last = curMax - r - r..
//last = curMax - k * r 直到 last 小于所处的数组的最大值,通过curMax % r得到余数可获取被替代的索引
//参考评论:
//There was a problem earlier (could not remember the problem number though). The problem is for a transform (x, y) -> (x+y, y) or (x, x+y), it asks whether you can reach the target pair from the source pair. The idea is exactly the same.
//The key is, the largest number in the target array must be 
//the one that got changed mostly recently. 
//So if you have a number a, compares it to the 
//sum of the rest r, the previous value for 
//that number must be a-r, and as long as a-r is 
//still larger than r, the previous value will be a-r-r, 
//so on so forth, until b=a-k*r is less than r. 
//So effectively b=a%r. You can do it step by step, 
//but for some test cases it will be TLE, 
//for example when r=1 you may have to do the process 
//too many times. Using % will give you b directly, 
//with the logic the same as step by step way

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> que(target.begin(), target.end());
        long total = 0;
        for (auto& e : target) 
            total += e;
        while (!que.empty()) {
            int m = que.top();
            que.pop();
            total -= m;
            if (m == 1 || total == 1)//[1, 100]的情况
                return true;
            if (m < total || total == 0 || m % total == 0)//m < total 正确情况下应该是当前最大值大于上一数组和，因为当前最大值是由上一数组和得到的
                return false;
            m = m % total;
            total += m;
            que.push(m);
        }
        return true;
  }
};
// @lc code=end

