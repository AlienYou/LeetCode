/*************************************************************************
	> File Name: LeetCode_121.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Mar 2020 06:37:24 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int MaxProfit(vector<int>& prices)
{
    int max = 0;
    int min = 0x7FFFFFFF;
    for (int i = 0; i < prices.size(); ++i)
    {
        if (min > prices[i])
            min = prices[i];
        else if (max < prices[i] - min)
                max = prices[i] - min;
    }
    return max;
}

void test(const char* testName, vector<int>& prices)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int ans = MaxProfit(prices);
    printf("%d\n", ans);
}

void test1()
{
    int stock[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(stock, stock + 6);
    test("Test1", prices);
}

int main()
{
    test1();
}
