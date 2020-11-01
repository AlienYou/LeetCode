/*************************************************************************
	> File Name: LeetCode_05.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Feb 2020 06:45:59 PM PST
 ************************************************************************/

//替换空格

#include<iostream>
#include<string>
#include<numeric>

#define CODELENGTH 3
using namespace std;

string ReplaceSpace(string s)
{
    string ans;
    if (s.length() == 0)
        return ans;
    int blankCount = accumulate(s.begin(), s.end(), 0, [](int count, char c) { return c == ' ' ? ++count : count; });
    ans.assign(blankCount * (CODELENGTH - 1) + s.length(), '\0');

    int endIndex = s.length() - 1;
    int newEndIndex = ans.length() - 1;

    while (endIndex >= 0)
    {
        if (s[endIndex] == ' ')
        {
            ans[newEndIndex--] = '0';
            ans[newEndIndex--] = '2';
            ans[newEndIndex--] = '%';
            --endIndex;
        }
        else
            ans[newEndIndex--] = s[endIndex--];
    }
    return ans;
}

void test(const char* testName, string& s, string expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (ReplaceSpace(s) == expected)
        printf("Passed.\n");
    else
        printf("%s.Failed.\n", ReplaceSpace(s).c_str());
}

void test1()
{
    string s = "I am strong";
    string expected = "I%20am%20strong";
    test("Test1", s, expected);
}

void test2()
{
    string s = "I'm  J ";
    string expected = "I'm%20%20J%20";
    test("Test2", s, expected);
}

void test3()
{
    string s;
    string expected;
    test("Test3", s, expected);
}

int main()
{
    test1();
    test2();
    test3();
}
