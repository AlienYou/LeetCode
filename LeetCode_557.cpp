/*************************************************************************
	> File Name: LeetCode_557.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Mar 2020 06:11:00 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string ReverseWords(string s)
{
    int start = 0;
    int end = 0;
    while (end < s.length() + 1)
    {
        if (s[end] == ' ' || s[end] == '\0')
        {
            int reverIndex = end - 1;
            while (start < reverIndex)
            {
                char temp = s[start];
                s[start++] = s[reverIndex];
                s[reverIndex--] = temp;
            }
            start = end + 1;
        }
        ++end;
    }
    return s;
}

void test(const char* testName, string s)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    string ans = ReverseWords(s);
    printf("%s\n", ans.c_str());
}

int main()
{
    test("Test1", "Let's take LeetCode  contest");
}
