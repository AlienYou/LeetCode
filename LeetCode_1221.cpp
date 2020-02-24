/*************************************************************************
	> File Name: LeetCode_1221.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Feb 2020 05:13:48 PM PST
 ************************************************************************/
//分割平衡字符串
#include<iostream>
#include<string>

using namespace std;

int BalancedStringSplit(string s)
{
    if (s.length() == 0)
        return 0;
    int endWin = 0;
    int countR = 0;
    int result = 0;
    while (endWin < s.length())
    {
        if (s[endWin] == 'R')
            ++countR;
        else if (s[endWin] == 'L')
            --countR;
        if (countR == 0)
            ++result;
        ++endWin;
    }
    return result;
}

void test(const char* testName, string s, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = BalancedStringSplit(s);
    if (ans == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", ans);
}

int main()
{
    test("Test1", "LR", 1);
    test("Test2", "RLRRLLRLRL", 4);    
    test("Test3", "RLLLRRRLR", 3);
    test("Test4", "RLRRLLLR", 3);
}
