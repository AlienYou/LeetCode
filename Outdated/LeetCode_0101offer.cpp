/*************************************************************************
	> File Name: LeetCode_0101offer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Feb 2020 06:21:21 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

bool IsUnique(string astr)
{
    char hashMap[128];
    memset(hashMap, '0', sizeof(hashMap[0]) * 128);
    for (int i = 0; i < astr.length(); ++i)
    {
        if (hashMap[astr[i]] == '1')
            return false;
        hashMap[astr[i]] = '1';
    }
    return true;
}

//利用位运算！题解的朋友太强了
bool IsUnique_2(string astr)
{
    int mapBit = 0x0;
    for (int i = 0; i < astr.length(); ++i)
    {
        int diff_bit = astr[i] - 'a';
        int bitCal = 1 << diff_bit;
        if (mapBit & bitCal)
            return false;
        mapBit |= bitCal;
    }
    return true;
}

void test(const char* testName, string astr, bool expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (IsUnique_2(astr) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

}

int main()
{
    test("Test1", "leetcode", false);
    test("Test2", "abc", true);
}
