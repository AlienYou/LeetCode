/*************************************************************************
	> File Name: LeetCode_1252.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Feb 2020 05:42:45 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int OddCells(int n, int m, vector<vector<int>>& indices)
{
    vector<int> matrix;
    matrix.assign(n * m, 0);
    
    for (int i = 0; i < indices.size(); i++)
    {
        for (int col = 0; col < m; ++col)
            ++matrix[indices[i][0] * m + col];
        for (int row = 0; row < n; ++row)
            ++matrix[row * m + indices[i][1]];
    }
    
    return accumulate(matrix.begin(), matrix.end(), 0, [](int count, int a){ if (a & 0x1) return  ++count; });
}
//运用面积的方式解决，最后剩下的非零值都是１，对应的就是为奇数值
int OddCells_2(int n, int m, vector<vector<int>>& indices)
{
    vector<int> rows(n);
    vector<int> cols(m);

    for (int i = 0; i < indices.size(); ++i)
    {
        rows[indices[i][0]] = !rows[indices[i][0]];
        cols[indices[i][1]] = !cols[indices[i][1]];
    }

    int c = 0, r = 0;
    for (int i = 0; i < rows.size(); ++i)
        if (rows[i]) ++r;
    for (int i = 0; i < cols.size(); ++i)
        if (cols[i]) ++c;
    return r * m + c * n - r * c * 2;
}

void test(const char* testName, int n, int m, vector<vector<int>>& indices, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = OddCells_2(n, m, indices);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", result);
}

void test1()
{
    int num[][2] = { {0, 1}, {1, 1} };
    vector<vector<int>> indices;
    indices.resize(2);
    for (int i = 0; i < 2; ++i)
        indices[i].assign(*(num + i), *(num + i) + 2);
    test("Test1", 2, 3, indices, 6);
}

void test2()
{
    int num[][2] = { {1, 1}, {0, 0} };
    vector<vector<int>> indices;
    indices.resize(2);
    for (int i = 0; i < 2; ++i)
        indices[i].assign(*(num + i), *(num + i) + 2);
    test("Test2", 2, 2, indices, 0);
}

int main()
{
    test1();
    test2();
}
