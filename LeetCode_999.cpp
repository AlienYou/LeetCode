/*************************************************************************
	> File Name: LeetCode_999.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Mar 2020 07:46:52 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i)
    {
        bool find = false;
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == 'R')
            {
                int result = 0;
                int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (int k = 0; k < 4; k++)
                {
                    int RTempX = i + direction[k][0];
                    int RTempY = j + direction[k][1];
                    while (RTempX >= 0 && RTempX < 8 && RTempY >= 0 && RTempY < 8)
                    {
                        if (board[RTempX][RTempY] == 'B')
                            break;
                        else if(board[RTempX][RTempY] == 'p')
                        {
                            result++;
                            break;
                        }
                        RTempX += direction[k][0];
                        RTempY += direction[k][1];
                    }
                }
                return result;
            }
        }
    }
    return 0;
}
