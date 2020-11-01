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

bool isValid(string s) {
        if (s.length() == 0)
            return true;
        if (s.length() % 2)
            return false;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (pairs.count(s[i]))
            {
                if (!st.empty() && st.top() == pairs[s[i]])
                    st.pop();
                else
                    return false;
            }
            else
                st.push(s[i]);
        }
        return st.empty();
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
