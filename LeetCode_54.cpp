/*************************************************************************
	> File Name: LeetCode_54.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jun 2020 03:31:47 AM PDT
 ************************************************************************/

#include<vector>
#include<iostream>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0)
        return vector<int>();
    int left = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int top = 0;
    vector<int> res(matrix.size() * matrix[0].size());
    int curIndex = 0;
    while (left <= right && top <= bottom)
    {
        for (int curL = left; curL <= right; ++curL)
            res[curIndex++] = matrix[top][curL];
        ++top;
        for (int curB = top; curB <= bottom; ++curB)
            res[curIndex++] = matrix[curB][right];
        --right;
        if (left <= right && top <= bottom)
        {
            for (int curR = right; curR >= left; --curR)
                res[curIndex++] = matrix[bottom][curR];
            --bottom;
            for (int curT = bottom; curT >= top; --curT)
                res[curIndex++] = matrix[curT][left];
            ++left;
        }
    } 
    return res;
}
