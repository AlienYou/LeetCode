/*************************************************************************
	> File Name: LeetCode_1071.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Mar 2020 06:36:03 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<numeric>
using namespace std;

string GcdOfStrings(string str1, string str2)
{
    if (str1.length() < str2.length())
        swap(str1, str2);
    int divisor = str2.length();
    while (str1.length() % divisor || str2.length() % divisor)
        --divisor;
    string result;
    while (divisor > 0)
    {
        bool isMatch = true;
        for (int i = 0; i < str1.length();)
        {
            for (int j = 0; j < divisor; )
            {
                if (str1[i++] != str2[j++])
                {
                    isMatch = false;
                    break;
                }
            }
            if (!isMatch)
                break;
        }
        if (isMatch)
        {
            for (int i = 0; i < divisor; ++i)
                result += str2[i];
            return result;
        }
        --divisor;
    }
    return result;
}

string GcdOfStrings_2(string str1, string str2)
{
    if (str1 + str2 != str2 + str1) return "";
    return str1.substr(0, gcd(str1.length(), str2.length()));
}

void test(const char* testName, string str1, string str2)
{
    if (testName == nullptr)
        return ;
    printf("%s:", testName);
    string result = GcdOfStrings_2(str1, str2);
    printf("%s\n", result.c_str());
}

int main()
{
    test("Test1", "ABCABCABCABC", "ABCABC");
    test("Test2", "ABABAB", "ABAB");
    test("Test3", "LEET", "CODE");
    test("Test4", "AAAA", "AAA");  
    test("Test5", "TAUXXTAUXXTAUXXTAUXXTAUXX", "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX");
}
