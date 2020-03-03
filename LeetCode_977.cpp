/*************************************************************************
	> File Name: LeetCode_977.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Mar 2020 05:40:23 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> sortedSquares(vector<int>& A)
{
    for (int i = 0; i < A.size(); ++i)
        A[i] *= A[i];
    int start = 0;
    int end = A.size() - 1;
    vector<int> B(A);
    int insertIndex = end;
    while (start <= end)
    {
        if (A[start] > A[end])
            B[insertIndex--] = A[start++];
        else
            B[insertIndex--] = A[end--];
    }
    return B;
}

void test(const char* testName, vector<int>& A)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = sortedSquares(A);
    for (auto &x : result)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    int num[] = {-4, -1, 0, 3, 11};
    vector<int> A(num, num + 5);
    test("Test1", A);
}

void test2()
{
    int num[] = {-5, -2, 1, 3, 4};
    vector<int> A(num, num + 5);
    test("Test2", A);
}

void test3()
{
    vector<int> A;
    test("Test3", A);
}

int main()
{
    test1();
    test2();
    test3();
}
