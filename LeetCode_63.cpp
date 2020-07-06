/*************************************************************************
	> File Name: LeetCode_63.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Jul 2020 08:40:20 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0)
        return 0;
    queue<pair<int,int>> que;
    que.emplace(0, 0);
    int endX = obstacleGrid.size() - 1;
    int endY = obstacleGrid[0].size() - 1;
    int result = 0;
    while (!que.empty())
    {
        auto curPoint = que.front();
        que.pop();
        if (obstacleGrid[curPoint.first][curPoint.second] == 1)
            continue;
        if (curPoint.first == endX && curPoint.second == endY)
        {
            result++;
            continue;
        }
        if (curPoint.first + 1 <= endX)
            que.emplace(curPoint.first + 1, curPoint.second);
        if (curPoint.second + 1 <= endY)
            que.emplace(curPoint.first, curPoint.second + 1);
    }
    return result;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0)
        return 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    int result = 0;
    vector<int> dp(m, 0);
    if (obstacleGrid[0][0] != 1)
        dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[j] = 0;
                continue;
            }
            if (j - 1 >= 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp.back();
}
