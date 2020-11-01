/*************************************************************************
	> File Name: LeetCode_322.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Mar 2020 07:10:25 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CoinChange(vector<int>& coins, int amount)
{
    vector<int> result(amount + 1, -1);
    result[0] = 0; 
    for (int i = 2; i < result.size(); ++i)
    {
        for (int j = 0; j < coins.size(); ++j)
        {
            if (i - coins[j] >= 0 && result[i - coins[j]] != -1)
            {
                int temp = result[i - coins[j]] + 1;
                if (result[i] == -1 || temp < result[i])
                    result[i] = temp;
            }
        }
    }
    return result[amount];
}

void CoinChangeCore(vector<int>& coins, int amount, int index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(count, ans);
        return;
    }
    if (index == coins.size())
        return;
    for (int k = amount / coins[index]; k >= 0 && k + count < ans; --k)
        CoinChangeCore(coins, amount - k * coins[index], index + 1, k + count, ans);
}

int CoinChange_Recursively(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.begin(), coins.end(), greater<int>());
    int ans = 0x7FFFFFFF;
    CoinChangeCore(coins, amount, 0, 0, ans);
    return ans == 0x7FFFFFFF ? -1 : ans;
}

void test(const char* testName, vector<int>& coins, int amount)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = CoinChange(coins, amount);
    int recur = CoinChange_Recursively(coins, amount);
    //printf("%d\n", ans);
    printf("%d\n", recur);
}

void test1()
{
    int nums[] = {1, 2, 5};
    vector<int> coins(nums, nums + 3);
    test("Test1", coins, 11);
}

void test2()
{
    int nums[] = {2};
    vector<int> coins(nums, nums + 1);
    test("Test2", coins, 3);
}

void test3()
{
    int nums[] = {1, 2, 4};
    vector<int> coins(nums, nums + 3);
    test("Test3", coins, 4);
}

void test4()
{
    int nums[] = {1};
    vector<int> coins(nums, nums + 1);
    test("Test4", coins, 0);
}

void test5()
{
    int nums[] = {493, 416, 144, 164, 314, 25};
    vector<int> coins(nums, nums + 6);
    test("Test5", coins, 5607);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
