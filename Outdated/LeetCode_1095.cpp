/*************************************************************************
	> File Name: LeetCode_1095.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Apr 2020 06:42:15 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int GetPeek(MountainArray& mountainArr, int left, int right)
{
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
int FindLeft(MountainArray& mountainArr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        int cur = mountainArr.get(mid);
        if (cur == target)
            return mid;
        else if (cur > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int FindRight(MountainArray& mountainArr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        int cur = mountainArr.get(mid);
        if (cur == target)
            return mid;
        else if (cur > target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int findInMountainArray(int target, MountainArray &mountainArr) {
    int peekIndex = GetPeek(mountainArr, 0, mountainArr.length() - 1);
    int seL = FindLeft(mountainArr, 0, peekIndex, target);
    int seR = FindRight(mountainArr, peekIndex + 1, mountainArr.length() - 1, target);
    return seL == -1 ? seR : seL;
}
