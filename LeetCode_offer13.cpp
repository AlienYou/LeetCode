/*************************************************************************
	> File Name: LeetCode_offer13.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Apr 2020 07:04:06 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<bool> grid;
int bitSum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int move(int curX, int curY, int m, int n, int k)
{
    if (curX < 0 || curY < 0 || curX > m - 1 || curY > n - 1 || bitSum(curX) + bitSum(curY) > k ||grid[curX * n + curY] == true)
        return 0;
    grid[curX * n + curY] = true;
    return move(curX + 1, curY, m, n, k) + move(curX - 1, curY, m, n, k) + move(curX, curY + 1, m, n, k) + move(curX, curY - 1, m, n, k) + 1;
}
int movingCount(int m, int n, int k) {
    grid.assign(m * n, false);
    return move(0, 0, m, n, k);;
}
