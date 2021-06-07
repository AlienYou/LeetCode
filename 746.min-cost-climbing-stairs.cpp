/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (50.78%)
 * Likes:    3430
 * Dislikes: 720
 * Total Accepted:    254.1K
 * Total Submissions: 482.3K
 * Testcase Example:  '[10,15,20]'
 *
 * You are given an integer array cost where cost[i] is the cost of i^th step
 * on a staircase. Once you pay the cost, you can either climb one or two
 * steps.
 * 
 * You can either start from the step with index 0, or the step with index 1.
 * 
 * Return the minimum cost to reach the top of the floor.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: Cheapest is: start on cost[1], pay that cost, and go to the
 * top.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping
 * cost[3].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        for (int i = 2; i < n + 1; ++i) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        
        }
        return cost[n];
    }
};
// @lc code=end

