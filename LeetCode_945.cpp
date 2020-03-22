/*************************************************************************
	> File Name: LeetCode_945.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Mar 2020 09:42:59 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());
    int move = 0;
    for (int i = 1; i < A.size(); ++i)
    {
        if (A[i] <= A[i - 1])
        {
            int pre = A[i];
            A[i] = A[i - 1] + 1;
            move += A[i] - pre;
        }
    }
    return move;
}

void test(const char* testName, vector<int>& A)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int result = minIncrementForUnique(A);
    printf("%d\n", result);
}

void test1()
{
    vector<int> A{3, 2, 1, 2, 1, 7};
    test("Test1", A);
}

void test2()
{
    vector<int> A{1, 2, 2};
    test("Test2", A);
}

int main()
{
    test1();
    test2();
}
