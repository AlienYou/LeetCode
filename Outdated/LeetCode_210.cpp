/*************************************************************************
	> File Name: LeetCode_210.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 May 2020 02:18:44 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> edge;
    vector<int> result;
    vector<int> visit;
    bool isLoop = false;
    void DFS(int u)
    {
        visit[u] = 1;
        for (int& v : edge[u])
        {
            if (visit[v] == 0)
            {
                DFS(v);
                if (isLoop)
                    return;
            }
            else if (visit[v] == 1)
            {
                isLoop = true;
                return;
            }
        }
        visit[u] = 2;
        result.push_back(u);
    }
    vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visit.resize(numCourses);
        for (auto& sche : prerequisites)
            edge[sche[1]].push_back(sche[0]);
        for (int i = 0; i < numCourses && !isLoop; ++i)
        {
            if (!visit[i])
                DFS(i);
        }
        if (isLoop)
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visit.resize(numCourses);
        for (auto& sche : prerequisites)
        {
            edge[sche[1]].push_back(sche[0]);
            visit[sche[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
            if (!visit[i])
                que.push(i);
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            result.push_back(front);
            for (int& u : edge[front])
            {
                --visit[u];
                if (!visit[u])
                    que.push(u);
            }
        }
        if (result.size() != numCourses)
            return {};
        return result;
    }
};
