/*************************************************************************
	> File Name: LeetCode_1323.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Feb 2020 05:01:26 PM PST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define MAXBITNUMBER 11

int maximum69Number(int num)
{
    char strNum[MAXBITNUMBER]; 
    sprintf(strNum, "%d", num);

    int i = 0;
    while (strNum[i] != '\0')
    {
        if (strNum[i] == '6')
        {
            strNum[i] = '9';
            break;
        }
        i++;
    }

    return atoi(strNum);
}

void test(const char* testName, int num, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = maximum69Number(num);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main()
{
    test("Test1", 996, 999);
    test("Test2", 9669, 9969);
}
