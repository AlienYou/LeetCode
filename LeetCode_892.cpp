/*************************************************************************
	> File Name: LeetCode_892.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Mar 2020 06:37:12 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] > 0)
            {
                result += (grid[i][j] << 2) + 2;
                if (j + 1 < grid[0].size() && grid[i][j + 1] > 0)
                    result -= min(grid[i][j + 1], grid[i][j]) << 1;
                if (i + 1 < grid.size() && grid[i + 1][j] > 0)
                    result -= min(grid[i + 1][j], grid[i][j]) << 1;
            }
        }
    }
    return result;
}
