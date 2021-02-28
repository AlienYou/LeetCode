/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    5281
 * Dislikes: 214
 * Total Accepted:    540.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    public:
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indgree(numCourses, 0);
        int n = prerequisites.size();
        queue<int> que;
        vector<vector<int>> edges(numCourses, vector<int>());
        for (int i = 0; i < n; ++i) {
            indgree[prerequisites[i][0]]++;
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indgree[i] == 0)
                que.push(i);
        }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            --numCourses;
            for (auto& ele : edges[cur]) {
                --indgree[ele];
                if (indgree[ele] == 0)
                    que.push(ele);
            }
        }
        return numCourses == 0;
    }
    
    bool valid = true;
    vector<int> visited;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        vector<vector<int>> edges(numCourses, vector<int>());
        int size = prerequisites.size();
        for (int i = 0; i < size; ++i) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                DFS(i, edges);
            }
        }
        
        return valid;
    }   
    
    void DFS(int i, vector<vector<int>>& edges) {
        visited[i] = 1;
        for (auto& ele : edges[i]) {
            if (visited[ele] == 1) {
                valid = false;
                return;
            } else if (visited[ele] == 0) {
                 DFS(ele, edges);           
                if (!valid)
                    return;
            }
        }
        
        visited[i] = 2;
    }
};
// @lc code=end

