/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 *
 * https://leetcode.com/problems/furthest-building-you-can-reach/description/
 *
 * algorithms
 * Medium (51.69%)
 * Likes:    839
 * Dislikes: 40
 * Total Accepted:    27.3K
 * Total Submissions: 57.6K
 * Testcase Example:  '[4,2,7,6,9,14,12]\n5\n1'
 *
 * You are given an integer array heights representing the heights of
 * buildings, some bricks, and some ladders.
 * 
 * You start your journey from building 0 and move to the next building by
 * possibly using bricks or ladders.
 * 
 * While moving from building i to building i+1 (0-indexed),
 * 
 * 
 * If the current building's height is greater than or equal to the next
 * building's height, you do not need a ladder or bricks.
 * If the current building's height is less than the next building's height,
 * you can either use one ladder or (h[i+1] - h[i]) bricks.
 * 
 * 
 * Return the furthest building index (0-indexed) you can reach if you use the
 * given ladders and bricks optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 * Output: 4
 * Explanation: Starting at building 0, you can follow these steps:
 * - Go to building 1 without using ladders nor bricks since 4 >= 2.
 * - Go to building 2 using 5 bricks. You must use either bricks or ladders
 * because 2 < 7.
 * - Go to building 3 without using ladders nor bricks since 7 >= 6.
 * - Go to building 4 using your only ladder. You must use either bricks or
 * ladders because 6 < 9.
 * It is impossible to go beyond building 4 because you do not have any more
 * bricks or ladders.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
 * Output: 7
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: heights = [14,3,19,3], bricks = 17, ladders = 0
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 1 <= heights[i] <= 10^6
 * 0 <= bricks <= 10^9
 * 0 <= ladders <= heights.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> que;
        
        for (int i = 0; i < heights.size() - 1; ++i) {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
                que.push(d);
            if (que.size() > ladders) {
                bricks -= que.top();
                que.pop();
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
    
    int res = 0;
    
    int furthestBuilding1(vector<int>& heights, int bricks, int ladders) {
        dfs(heights, 0, bricks, ladders);    
        return res;
    }
    
    void dfs(vector<int>& heights, int curInd, int bricks, int ladders) {
        if (curInd == heights.size() - 1) {
            res = curInd;
            return;
        }
        res = max(res, curInd);
        if (heights[curInd] < heights[curInd + 1]) {
            if (bricks >= heights[curInd + 1] - heights[curInd])
                dfs(heights, curInd + 1, bricks - (heights[curInd + 1] - heights[curInd]), ladders);
            if (ladders > 0)
                dfs(heights, curInd + 1, bricks, ladders - 1);
        } else 
            dfs(heights, curInd + 1, bricks, ladders);
        
    }
};
// @lc code=end
