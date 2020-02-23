/*************************************************************************
	> File Name: LeetCode_offer17.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2020 06:00:25 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int CharToInt(char* bigNum, int length)
{
    if (bigNum == nullptr || length <= 0)
        return 0;
    
    int number = 0; 

    for (int i = 0; i < length; i++)
        number = number * 10 + bigNum[i] - '0';
    return number;
}

bool Increment(char* bigNum, int n, vector<int>& numbers)
{
    if (bigNum == nullptr)
        return true;
    for (int i = n - 1; i >= 0; --i)
    {
        bool carryBit = false;
        int sum = bigNum[i] - '0' + 1;
        if (sum == 10)
        {
            carryBit = true;
            sum -= 10;
        }
        bigNum[i] = sum + '0';
        if (!carryBit)
        {
            numbers.push_back(atoi(bigNum));
            return false;
        }
    }
    return true;
}

vector<int> PrintNumber(int n)
{
    vector<int> numbers;
    if (n <= 0)
        return numbers;
    
    char* bigNum = new char[n + 1];
    memset(bigNum, '0', sizeof(bigNum[0]) * (n + 1));
    bigNum[n] = '\0';

    while (!Increment(bigNum, n, numbers));
    
    delete []bigNum;

    return numbers;
}

void test(const char* testName, int n)
{
    if (testName == nullptr)
        return ;
    printf("%s:\n", testName);
    vector<int> ans = PrintNumber(n);
    for (auto it : ans)
    {
        printf("%d\t", it);
        if (it % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

int main()
{
    test("Test1", 1);
    test("Test2", 2);
    test("Test3", 3);
}
