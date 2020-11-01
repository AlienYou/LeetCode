/*************************************************************************
	> File Name: LeetCode_542.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Apr 2020 09:52:01 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    queue<pair<int, int>> que;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (!matrix[i][j])
                que.push(make_pair(i, j));
        }
    }
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; ++i)
        {
            pair<int, int> cur = que.front();
            que.pop();
            for (int j = 0; j < 4; ++j)
            {
                int newX = cur.first + dir[j][0];
                int newY = cur.second + dir[j][1];
                if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()
                    && matrix[newX][newY] && !(matrix[newX][newY] >> 1))
                {
                    matrix[newX][newY] ^= ((matrix[cur.first][cur.second] >> 1) + 1) << 1;
                    que.push(make_pair(newX, newY));
                }
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
            if (matrix[i][j])
                matrix[i][j] >>= 1;
    }

    return matrix;
}
