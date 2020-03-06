/*************************************************************************
	> File Name: LeetCode_1025.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Mar 2020 06:45:04 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


bool DivisorGame(int N)
{
    vector<bool> divisor(N + 1, false);
    
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j <= (i >> 1); ++j)
        {
            if (i % j == 0 && divisor[i] == false)
                divisor[i] = divisor[i] || !divisor[i - 1];
            if (divisor[i])
                break;
        }
    }
    return divisor[N];
}

void test(const char* testName, int N)
{
    if (testName == nullptr)
        return;
    printf("%s: %d ", testName, N);
    if (DivisorGame(N))
        printf("Win\n");
    else
        printf("Lose\n");
}

int main()
{
    test("Test1", 2);
    test("Test2", 3);
    test("Test3", 4);
    test("Test4", 5);
    test("Test5", 6);
}
