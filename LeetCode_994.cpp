/*************************************************************************
	> File Name: LeetCode_994.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Mar 2020 05:55:46 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<set>
using namespace std;

int OrangeRotting(vector<vector<int>>& grid)
{
    queue<pair<int,int>> rotQue;
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)    
            if (grid[i][j] == 2)
                rotQue.push(make_pair(i, j));
    int rows = grid.size();
    int cols = grid[0].size();
    int minu = 0;
    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!rotQue.empty())
    {
        int size = rotQue.size();
        for (int i = 0; i < size; ++i)
        {
            pair<int, int> rotOrange = rotQue.front();
            rotQue.pop();
            for (int x = 0; x < 4; ++x)
            {
                int yPos = rotOrange.first + dir[x][0];
                int xPos = rotOrange.second + dir[x][1];
                if (xPos >= 0 && xPos < cols && yPos >= 0 && yPos < rows && grid[yPos][xPos] == 1)
                {
                    rotQue.push(make_pair(yPos, xPos));
                    grid[yPos][xPos] = 2;
                }
            }
        }
        if (!rotQue.empty())
            ++minu;
    }

    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == 1) return -1;
    return minu;
}

int OrangeRotting_gather(vector<vector<int>>& grid)
{
    queue<pair<int, int>> rotQue;
    multiset<pair<int, int>> fresh;
    for (int i = 0; i < grid.size(); ++i)
    {   
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 2)
                rotQue.push(make_pair(i, j));
            else if (grid[i][j] == 1)
                fresh.insert(make_pair(i, j));
        }
    }

    vector<pair<int, int>> dir;
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(0, -1));
    int minu = 0;
    while (!rotQue.empty())
    {
        int size = rotQue.size();
        for (int i = 0; i < size; ++i)
        {
            pair<int, int> rotOrange = rotQue.front();
            rotQue.pop();
            for (int d = 0; d < dir.size(); ++d)
            {
                auto temp = make_pair(rotOrange.first + dir[d].first, rotOrange.second + dir[d].second);
                if (fresh.find(temp) != fresh.end())
                {
                    fresh.erase(temp);
                    rotQue.push(temp);
                }
            }
        }
        if (!rotQue.empty())
            ++minu;
    }

    if (!fresh.empty()) return -1;
    return minu;
}

void test(const char* testName, vector<vector<int>>& grid)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = OrangeRotting_gather(grid);
    printf("%d\n", ans);
}

void test1()
{
    int num[][3] = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> grid;
    grid.resize(3);
    for (int i = 0; i < 3; ++i)
        grid[i].assign(*(num + i), *(num + i) + 3);
    test("Test1", grid);
}

void test2()
{
    int num[][3] = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    vector<vector<int>> grid;
    grid.resize(3);
    for (int i = 0; i < 3; ++i)
        grid[i].assign(*(num + i), *(num + i) + 3);
    test("Test2", grid);
}

void test3()
{
    int num[][2] = { {0, 2} };
    vector<vector<int>> grid;
    grid.resize(1);
    for (int i = 0; i < 1; ++i)
        grid[i].assign(*(num + i), *(num + i) + 2);
    test("Test3", grid);
}

int main()
{
    test1();
    test2();
    test3();
}
