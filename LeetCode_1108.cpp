/*************************************************************************
	> File Name: LeetCode_1108.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2020 05:45:59 PM PST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

string DefangedIPAddr(string& address)
{
    for (int i = 0; i < address.length(); i++)
        if (address[i] == '.')
        {    
            address.replace(i, 1, "[.]", 3);
            i += 3;
        }
    return address;
}

void test(const char* testName, string& address, string& expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (DefangedIPAddr(address) == expected)
        printf("Passed.\n");
    else
        printf("%s.Failed.\n", DefangedIPAddr(address).c_str());
}

void test1()
{
    string address = "1.1.1.1";
    string expected = "1[.]1[.]1[.]1";
    test("Test1", address, expected);
}

void test2()
{
    string address = "255.100.50.0";
    string expected = "255[.]100[.]50[.]0";
    test("Test2", address, expected);
}

int main()
{
    test1();
    test2();
}
