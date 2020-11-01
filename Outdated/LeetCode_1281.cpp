/*************************************************************************
	> File Name: LeetCode_1281.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Feb 2020 06:16:05 PM PST
 ************************************************************************/
//整数的各位积和之差
#include<iostream>

#define MAX 100000

using namespace std;

int SubtractProductAndSum(int n)
{
    if (n < 1 || n > MAX)
        return 0;
    int product = 1;
    int sum = 0;

    while (n != 0)
    {
        int mod = n%10;
        n /= 10;
        product *= mod;
        sum += mod;
    }
    
    return product - sum;
}

void test(const char* testName, int n, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (SubtractProductAndSum(n) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main()
{
    test("Test1", 123, 0);
    test("Test2", 234, 15);
    test("Test3", 100, -1);
}
