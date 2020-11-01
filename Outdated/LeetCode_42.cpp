/*************************************************************************
	> File Name: LeetCode_42.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Apr 2020 06:42:59 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() == 0 || height.size() == 1)
        return 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; ++i)
        left_max[i] = max(left_max[i - 1], height[i]);
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; --i)
        right_max[i] = max(right_max[i + 1], height[i]);
    int result = 0;
    for (int i = 0; i < size; ++i)
        result += min(left_max[i], right_max[i]) - height[i];
    return result;
}

 int trap2(vector<int>& height) {
    if (height.size() == 0 || height.size() == 1)
        return 0;
    int current = 0;
    int result = 0;
    stack<int> indexSt;
    while (current < height.size())
    {
        while(!indexSt.empty() && height[current] > height[indexSt.top()])
        {
            int top = indexSt.top();
            indexSt.pop();
            while (!indexSt.empty() && height[top] == height[indexSt.top()])
                indexSt.pop();
            if (indexSt.empty())
                break;
            int distance = current - indexSt.top() - 1;
            int heightN = min(height[current], height[indexSt.top()]) - height[top];
            result += distance * heightN;
        }
        indexSt.push(current++);
    }
    return result;
}

int trap3(vector<int>& height) {
    if (height.size() == 0 || height.size() == 1)
        return 0;
    int start = 0, end = height.size() - 1, left_max = 0, right_max = 0;
    int result = 0;
    while (start < end)
    {
        if (height[start] < height[end])
        {
            height[start] >= left_max? left_max = height[start] : result += left_max - height[start];
            ++start;
        }
        else
        {
            height[end] >= right_max? right_max = height[end] : result += right_max - height[end];
            --end;
        }
    }
    return result;
}
