/*************************************************************************
	> File Name: LeetCode_1309.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 08:35:23 PM PST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

const char* alpMap = "abcdefghijklmnopqrstuvwxyz";

string FreqAlphabets(string s)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '3' || s[i + 2] != '#' )
            ans.push_back(alpMap[s[i] - '1']);
        else
        {   
            ans.push_back(alpMap[(s[i] - '0') * 10 + s[i + 1] - '0' - 1]);
            i += 2;
        }
    }

    return ans;
}

void test(const char* testName, string s)
{
    if (testName == nullptr)
        return;
    string ans = FreqAlphabets(s);
    printf("%s\n", ans.c_str());
}

int main()
{
    test("Test1", "10#11#12");
    test("Test2", "25#");
    test("Test3", "12345610#11#");
}
