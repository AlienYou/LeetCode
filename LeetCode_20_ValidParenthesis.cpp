/*************************************************************************
	> File Name: LeetCode_20_ValidParenthesis.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2020 08:23:33 PM PST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid(string s)
{
    if (s.length() == 0)
        return true;
    if (s.length() & 0x1 == 1)
        return false;
    int right = 0;
    stack<char> charStack;

    while (s[right] != '\0')
    {
        if (s[right] == '(' || s[right] == '[' || s[right] == '{')
            charStack.push(s[right]);
        else
        {
            if (!charStack.empty())
            {
                char top = charStack.top();
                int diff = s[right] - top;
                if (diff == 1 || diff == 2)
                    charStack.pop();
                else
                    return false;
            }
            else
                return false;
        }
        ++right;
    }
    
    if (charStack.empty())
        return true;
    return false;
}

void test(const char* testName, string s, bool expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (isValid(s) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main()
{
    test("Test1", "()", true); 
    test("Test2", "{[()]}", true);
    test("Test3", "", true);
    test("Test4", "[[]", false);
    test("Test5", "({)}", false);
}
