/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 *
 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 *
 * algorithms
 * Hard (34.95%)
 * Likes:    789
 * Dislikes: 35
 * Total Accepted:    26.4K
 * Total Submissions: 65.2K
 * Testcase Example:  '6\n[2,10,3,1,5,8]\n[5,4,3,9,7,2]\n2'
 *
 * You are given two integers n and k and two integer arrays speed and
 * efficiency both of length n. There are n engineers numbered from 1 to n.
 * speed[i] and efficiency[i] represent the speed and efficiency of the i^th
 * engineer respectively.
 * 
 * Choose at most k different engineers out of the n engineers to form a team
 * with the maximum performance.
 * 
 * The performance of a team is the sum of their engineers' speeds multiplied
 * by the minimum efficiency among their engineers.
 * 
 * Return the maximum performance of this team. Since the answer can be a huge
 * number, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation: 
 * We have the maximum performance of the team by selecting engineer 2 (with
 * speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
 * That is, performance = (10 + 5) * min(4, 7) = 60.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1,
 * engineer 2 and engineer 5 to get the maximum performance of the team. That
 * is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= <= k <= n <= 10^5
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 10^5
 * 1 <= efficiency[i] <= 10^8
 * 
 * 
 */

//想不到，想不到
//算法思路：effeciency尽可能大，speed由于取k种最小的，所以对应的也是找能够尽量最小值中的最大、
//可以用pair构成一个数组，按照speed的从大到小排序，这样每次遍历一定是当前最小的speed
//同时用一个优先级队列（小顶堆）维护当前effeciency的k个最大值
//每次入队一定会更新speed最小值和effeciency的总和，超过k个数出队一个，
//对应的speed也出队

// @lc code=start
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i)
            vec[i] = {efficiency[i], speed[i]};
        sort(vec.begin(), vec.end(), [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first > p2.first;});
        priority_queue<int, vector<int>, greater<int>> que;
        
        long ans = 0, cur = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int e = vec[i].first;
            int s = vec[i].second;
            if (que.size() >= k) {
                cur -= que.top();
                que.pop();
            }
            cur += s;
            que.push(s);
            ans = max(ans, cur * e);
        }
        return ans % (int)(1e9+7);
    }
};
// @lc code=end

