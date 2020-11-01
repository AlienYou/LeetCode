/*************************************************************************
	> File Name: LeetCode_offer0106.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Mar 2020 06:55:04 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string compressString(string S)
{
    string result;
    int count = 0;
    char current = S[0];
    for (int i = 0; i <= S.length(); ++i)
    {
        if (current == S[i])
            ++count;
        else
        {
            result += current;
            result += to_string(count);
            count = 0;
            current = S[i--];
        }
    }
    return result.length() < S.length() ? result : S;
}

void test(const char* testName, string S)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    printf("%s\n", compressString(S).c_str());
}

int main()
{
    test("Test1", "aabcccccaaa");
}
