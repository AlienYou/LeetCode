/*************************************************************************
	> File Name: LeetCode_1351.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Feb 2020 06:05:32 PM PST
 ************************************************************************/

//有序矩阵的负数个数

#include<iostream>
#include<vector>

using namespace std;

int CountNegatives(vector<vector<int>>& grid)
{
    if (grid.size() == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        int start = 0;
        int end = grid[i].size() - 1;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (grid[i][mid] < 0 && (mid - 1 < 0 || grid[i][mid - 1] >= 0))
            {  
                count += grid[i].size() - mid;
                break;
            }
            else if (grid[i][mid] < 0 && grid[i][mid - 1] < 0)
                end = mid - 1;
            else 
                start = mid + 1;
        }
    }
    return count;
}

int CountNegatives_2(vector<vector<int>>& grid)
{
    if (grid.size() == 0)
        return 0;
    int count = 0;
    int cols = grid[0].size();
    int pos = grid[0].size() - 1;
    for (auto it : grid)
    {
        int i;
        for (i = pos; i >= 0; --i)
        {
            if (it[i] >= 0)
            {
                if (i + 1 < cols)
                {
                    pos = i + 1;
                    count += cols - pos;
                }
                break;
            }
        }
        if (i == -1)
        {
            pos = -1;
            count += cols;
        }
    }
    return count;
}

void test(const char* testName, vector<vector<int>>& grid, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (CountNegatives_2(grid) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    int num[][4] = { {4, 3, 2, 1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3} };
    vector<vector<int>> grid;
    grid.resize(4);
    for (int i = 0; i < 4; i++)
        grid[i].insert(grid[i].begin(), *(num + i), *(num + i) + 4);
    test("Test1", grid, 7);
}

void test2()
{
    int num[][3] = { {1, 2, 3}, {2, 3, 4}, {2, 4, 4} };
    vector<vector<int>> grid;
    grid.resize(3);
    for (int i = 0; i < 3; i++)
        grid[i].insert(grid[i].begin(), *(num + i), *(num + i) + 3);
    test("Test2", grid, 0);
}

void test3()
{
    vector<vector<int>> grid;
    test("Test3", grid, 0);
}

void test4()
{
    int num[][4] = { {1, -2, -3, -4}, {0, 0, -3, -4} };
    vector<vector<int>> grid;
    grid.resize(2);
    for (int i = 0; i < 2; i++)
        grid[i].insert(grid[i].begin(), *(num + i), *(num + i) + 4);
    test("Test4", grid, 5);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
