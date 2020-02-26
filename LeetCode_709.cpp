/*************************************************************************
	> File Name: LeetCode_709.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Feb 2020 07:44:48 PM PST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

string ToLowerCase(string& str)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return str;
}

void test(const char* testName, string str, string expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    string ans = ToLowerCase(str);
    if (str == expected)
        printf("Passed.\n");
    else
        printf("%s.Failed.\n", str.c_str());
}

int main()
{
   test("Test1", "Hello", "hello"); 
}
