/*************************************************************************
	> File Name: LeetCode_695.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Mar 2020 06:47:00 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int Core(vector<vector<int>>& grid, int row, int col, int rows, int cols)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0)
        return 0;
    
    grid[row][col] = 0;
    return Core(grid, row + 1, col, rows, cols) + Core(grid, row - 1, col, rows, cols) + Core(grid, row, col + 1, rows, cols) + Core(grid, row, col - 1, rows, cols) + 1;
}

int MaxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxLand = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            int count = 0;
            if (grid[i][j] == 1)
            {
                count = Core(grid, i, j, grid.size(), grid[0].size());
                maxLand = max(count, maxLand);
            }
        }
    }
    return maxLand;
}

void test(const char* testName, vector<<vector<int>>& grid)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = MaxAreaOfIsland(grid);
    printf("%d\n", result);
}

void test1()
{
    int land[][] = {{0, 0, 1, 0}}
    vector<vector<int>> grid;
}
