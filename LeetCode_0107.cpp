/*************************************************************************
	> File Name: LeetCode_0107.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Apr 2020 12:48:34 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    auto newMatrix = matrix;
    int n = matrix.size();
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            newMatrix[j][n - i - 1] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = newMatrix[i][j];
}

void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int bound = n >> 1;
    for (int i = 0; i < bound; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

void test()
{
    vector<vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate2(matrix);
    for (auto x : matrix)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

int main()
{
    test();
}
