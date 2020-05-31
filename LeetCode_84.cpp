/*************************************************************************
	> File Name: LeetCode_84.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 07:32:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int largestRectangleArea1(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int res = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        int curLeft = i;
        while (curLeft > left && heights[curLeft - 1] >= heights[i]) curLeft--;
        int curRight = i;
        while (curRight < right && heights[curRight + 1] >= heights[i]) curRight++;
        res = max(res, (curRight - curLeft + 1) * heights[i]);            
    }
    return res;
}
int largestRectangleArea2(vector<int>& heights) {
    if (heights.size() == 0)
        return 0;
    if (heights.size() == 1)
        return heights[0];
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0)
        return 0;
    vector<int> temp(heights.size() + 2, 0);
    copy(heights.begin(), heights.end(), temp.begin() + 1);
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < temp.size(); ++i)
    {
        while (!stk.empty() && temp[stk.top()] > temp[i])
        {
            int curHeight = temp[stk.top()];
            stk.pop();
            int left = stk.top();
            ans = max(ans, (i - left - 1) * curHeight);
        }
        stk.push(i);
    }
    return ans;
}
