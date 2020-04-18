/*************************************************************************
	> File Name: LeetCode_11.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Apr 2020 11:30:02 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

// int maxArea(vector<int>& height) {
//     int maxArea = 0;
//     for (int i = 0; i < height.size(); ++i)
//     {
//         int area = 1;
//         for (int j = height.size() - 1; j > i; --j)
//         {
//             area = min(height[j], height[i]) * (j - i);
//             maxArea = max(area, maxArea);
//         }
//     }
//     return maxArea;
// }
int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(area, maxArea);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}
