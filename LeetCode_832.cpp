/*************************************************************************
	> File Name: LeetCode_832.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Feb 2020 09:20:01 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> FlipAndInvertImage(vector<vector<int>>& A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        int start = 0, end = A[0].size() - 1;
        while (start < end)
        {
            int temp = A[i][start] ^ 1;
            A[i][start] = A[i][end] ^ 1;
            A[i][end] = temp;
            ++start;
            --end;
        }
        if (start == end)
            A[i][start] ^= 1;
    }
    return A;
}

void test(const char* testName, vector<vector<int>>& A)
{
    if (testName == nullptr)
        return;
    vector<vector<int>> ans = FlipAndInvertImage(A);
    for (auto x : ans)
    {
        for (auto y : x)
            printf("%d ", y);
        printf("\n");
    }
}

void test1()
{
    int num[][3] = { {1, 1, 0}, {1, 0, 1}, {0, 0, 0} };
    vector<vector<int>> image;
    image.resize(3);
    for (int i = 0; i < 3; i++)
    {
        image[i].assign(*(num + i), *(num + i) + 3);
    }

    test("Test1", image);
}

int main()
{
    test1();
}
