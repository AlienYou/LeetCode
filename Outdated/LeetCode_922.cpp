/*************************************************************************
	> File Name: LeetCode_922.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Mar 2020 11:27:29 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> SortArrayByParityII(vector<int>& A)
{
    int oddIndex = 1;
    for (int i = 0; i < A.size(); i += 2)
    {
        if (A[i] & 1)
        {
            while (A[oddIndex] & 1)
                oddIndex += 2;
            swap(A[i], A[oddIndex]);
        }
    }
    return A;
}
