/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (48.13%)
 * Likes:    2218
 * Dislikes: 209
 * Total Accepted:    166.4K
 * Total Submissions: 343.8K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 * 
 * Recall that a graph is bipartite if we can split its set of nodes into two
 * independent subsets A and B, such that every edge in the graph has one node
 * in A and another node in B.
 * 
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists. Each node is an integer
 * between 0 and graph.length - 1. There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 * Output: true
 * Explanation: We can divide the vertices into two groups: {0, 2} and {1,
 * 3}.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * Output: false
 * Explanation: We cannot find a way to divide the set of nodes into two
 * independent subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= graph.length <= 100
 * 0 <= graph[i].length < 100
 * 0 <= graph[i][j] <= graph.length - 1
 * graph[i][j] != i
 * All the values of graph[i] are unique.
 * The graph is guaranteed to be undirected. 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isBipartite1(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0 && !sameColor(graph, colors, 1, i))
                return false;
        }
        return true;
    }
    
    bool sameColor(vector<vector<int>>& graph, vector<int>& colors, int color, int i) {
        if (colors[i] != 0) {
            return colors[i] == color;
        }
        colors[i] = color;
        for (auto& ele : graph[i]) {
            if (!sameColor(graph, colors, -color, ele))
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0)
                continue;
            queue<int> que;
            que.push(i);
            colors[i] = 1;
            while (!que.empty()) {
                int cur = que.front();
                que.pop();
                for (auto& ele : graph[cur]) {
                    if (colors[ele] == 0) {
                        colors[ele] = -colors[cur];
                        que.push(ele);
                    } else if (colors[ele] == colors[cur])
                        return false;
                }
            }
        } 
        return true;
    }
};
// @lc code=end

