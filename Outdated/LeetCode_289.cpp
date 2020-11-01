/*************************************************************************
	> File Name: LeetCode_289.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Apr 2020 09:19:17 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void gameOfLife(vector<vector<int>>& board) {
    if (board.size() == 0)
        return;
    int sizeX = board.size();
    int sizeY = board[0].size();
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            int liveCount = 0;
            for (int k = 0; k < 8; ++k)
            {
                int cellX = i + dir[k][0];
                int cellY = j + dir[k][1];
                if (cellX >= 0 && cellX < sizeX && cellY >= 0 && cellY < sizeY && (board[cellX][cellY] & 1))
                    ++liveCount;
            }
            if (liveCount >= 2 && liveCount <= 3)
            {   
                if (board[i][j] & 1)
                    board[i][j] |= 2;
                else if (liveCount == 3)
                    board[i][j] |= 2;
            }
        }
    }
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            board[i][j] >>= 1;
        }
    }
}
