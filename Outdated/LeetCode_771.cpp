/*************************************************************************
	> File Name: LeetCode_771.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Feb 2020 08:26:57 PM PST
 ************************************************************************/
//宝石与石头

#include<iostream>
#include<string.h>

#define ASCNUMBER 256
using namespace std;

int NumbersOfJewelInStones(string J, string S)
{
    if (J.length() <= 0 || S.length() <= 0)
        return 0;
    char jewelMap[ASCNUMBER];
    int count = 0;
    memset(jewelMap, 0, sizeof(jewelMap[0]) * ASCNUMBER);
    for (int i = 0; i < J.length(); i++)
        ++jewelMap[J[i]];
    for (int i = 0; i < S.length(); i++)
        if (jewelMap[S[i]] == 1) ++count;
    return count;
}

void test(const char* testName, string J, string S, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int actual = NumbersOfJewelInStones(J, S);
    if (actual == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", actual);
}

void test1()
{
    string J = "aA";
    string S = "aAbbb";
    test("Test1", J, S, 2);
}

void test2()
{
    string J = "a";
    string S = "sssS";
    test("Test2", J, S, 0);
}

void test3()
{

}

int main()
{
    test1();
    test2();
}
