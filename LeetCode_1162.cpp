/*************************************************************************
	> File Name: LeetCode_1162.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Mar 2020 01:46:07 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    if (grid.size() == 0)
        return 0;
    queue<pair<int, int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j])
                que.push(make_pair(i, j));
        }
    }
    if (que.size() == 0 || que.size() == grid.size() * grid.size())
        return -1;
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pair<int, int> cur {-1, -1};
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        for (int i = 0; i < dir.size(); ++i)
        {
            int newX = cur.first + dir[i][0];
            int newY = cur.second + dir[i][1];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid.size() && grid[newX][newY] == 0)
            {
                que.push(make_pair(newX, newY));
                grid[newX][newY] = grid[cur.first][cur.second] + 1;
            }
        }
    }
    return grid[cur.first][cur.second] - 1;
}
