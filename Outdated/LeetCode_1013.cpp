/*************************************************************************
	> File Name: LeetCode_1013.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Mar 2020 07:42:02 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<functional>
using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0)
            return false;
        int sameSum = sum / 3;
        int count = 0;
        sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if (sum == sameSum)
            {
                count++;
                sum = 0;
            }
            if (count == 3)
                return true;
        }
        return false;
}    
