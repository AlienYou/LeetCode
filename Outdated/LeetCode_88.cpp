/*************************************************************************
	> File Name: LeetCode_88.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Mar 2020 11:24:31 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index = m + n - 1;
while (n)
{
        if (m == 0 || nums1[m - 1] <= nums2[n - 1])
            nums1[index--] = nums2[--n];
        else
            nums1[index--] = nums1[--m];
    }
}
