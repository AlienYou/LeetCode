/*************************************************************************
	> File Name: LeetCode_207.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Aug 2020 09:38:43 AM PDT
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*vector<int> visit;
    bool valid = true;
    void dfs(int u)
    {
        visit[u] = 1;
        for (int i = 0; i < edges[u].size(); ++i)
        {
            if (visit[edges[u][i]] == 0){    
                dfs(i);
                if (!valid)
                    return;
            }
            else if (visit[edges[u][i]] == 1){
                valid = false;
                return;
            }
        }
        visit[u] = 2;
    }

    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {   
        edges.resize(numCourses);
        visit.resize(numCourses);

        for (auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (!visit[i])
                dfs(i);
        } 
        return valid;
    }*/
vector<vector<int>> edges;
vector<int> indeg;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    indeg.resize(numCourses);

    
    for (auto& info : prerequisites)
    {
        edges[info[1]].push_back(info[0]);
        indeg[info[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    int visited = 0;
    while (!q.empty())
    {
        visited++;
        int node = q.front();
        q.pop();
        for (const int& info : edges[node])
        {
            indeg[info]--;
            if (indeg[info] == 0)
                q.push(info);
        }
    }
    return visited == numCourses;
}
