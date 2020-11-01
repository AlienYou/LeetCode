/*************************************************************************
	> File Name: LeetCode_200.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Apr 2020 10:35:08 AM PDT
 ************************************************************************/

#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0)
        return 0;
    queue<pair<int,int>> isQue;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == '1')
                isQue.push(make_pair(i, j));
        }
    }
    int result = 0;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!isQue.empty())
    {
        queue<pair<int,int>> singleIsQue;
        pair<int, int> cur = isQue.front();
        isQue.pop();
        if (grid[cur.first][cur.second] == '1')
        {
            grid[cur.first][cur.second] = '0';
            singleIsQue.push(cur);
            result++;
        }
        while (!singleIsQue.empty())
        {
            pair<int, int> is = singleIsQue.front();
            singleIsQue.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = is.first + dir[i][0];
                int newY = is.second + dir[i][1];
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()
                    && grid[newX][newY] == '1')
                    {
                        grid[newX][newY] = '0';
                        singleIsQue.push(make_pair(newX, newY));
                    }
            }
        }
    }
    return result;
}

class UnionFind
{
    public:
    UnionFind(vector<vector<char>>& grid)
    {
        count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {  
                    parent.push_back(i * grid[0].size() + j);
                    count++;
                }
                else
                    parent.push_back(-1);
            }
        }
    }
    int find(int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootX] = rootY;
            --count;
        }
    }

    int getCount() const
    {
        return count;
    }

    private:
        vector<int> parent;
        int count;
};
int numIslands1(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        UnionFind unF(grid);
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') unF.unite(i * m + j, (i - 1) * m + j);
                    if (i + 1 < n && grid[i + 1][j] == '1') unF.unite(i * m + j, (i + 1) * m + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') unF.unite(i * m + j, i * m + j - 1);
                    if (j + 1 < m && grid[i][j + 1] == '1') unF.unite(i * m + j, i * m + j + 1);
                }
            }
        }
        return unF.getCount();
    }
