/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (51.39%)
 * Likes:    4663
 * Dislikes: 884
 * Total Accepted:    259.6K
 * Total Submissions: 496K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a characters array tasks, representing the tasks a CPU needs to do,
 * where each letter represents a different task. Tasks could be done in any
 * order. Each task is done in one unit of time. For each unit of time, the CPU
 * could complete either one task or just be idle.
 * 
 * However, there is a non-negative integer n that represents the cooldown
 * period between two same tasks (the same letter in the array), that is that
 * there must be at least n units of time between any two same tasks.
 * 
 * Return the least number of units of times that the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: 
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 0
 * Output: 6
 * Explanation: On this case any permutation of size 6 would work since n = 0.
 * ["A","A","A","B","B","B"]
 * ["A","B","A","B","A","B"]
 * ["B","B","B","A","A","A"]
 * ...
 * And so on.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 * Output: 16
 * Explanation: 
 * One possible solution is
 * A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle
 * -> idle -> A
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= task.length <= 10^4
 * tasks[i] is upper-case English letter.
 * The integer n is in the range [0, 100].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        vector<int> count(26, 0);
        for (const auto & c : tasks) {
            count[c - 'A']++;
        }
        
        priority_queue<int> que;
        for (const auto& cc : count)
            if (cc)
                que.push(cc);
        int times = 0;
        
        while (!que.empty()) {
            vector<int> rest;
            int i = 0;
            for (; i <= n && !que.empty(); ++i) {
                int cur = que.top();
                que.pop();
                //cout << cur << endl;
                cur--;
                if (cur)
                    rest.push_back(cur);
            }
            if (rest.size() > 0)
                times += n + 1;
            else
                times += i;
            for (int j = 0; j < rest.size(); ++j)
                que.push(rest[j]);
        }
        
        return times;
    }
};
// @lc code=end

