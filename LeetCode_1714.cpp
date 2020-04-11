/*************************************************************************
	> File Name: LeetCode_1714.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Apr 2020 08:32:13 AM PDT
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> smallestK(vector<int>& arr, int k) {
if (arr.size() == 0 || k == 0)
        return vector<int>();
    vector<int> result;
    priority_queue<int> que;
    for (int i = 0; i < k; ++i)
    {
        que.push(arr[i]);
    }
    for (int i = k; i < arr.size(); ++i)
    {
        if (arr[i] < que.top())
        {
            que.push(arr[i]);
            que.pop();
        }
    }
    while (!que.empty())
    {
        result.emplace_back(que.top());
        que.pop();
    }
    return result;
}
