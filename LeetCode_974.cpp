/*************************************************************************
	> File Name: LeetCode_974.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 May 2020 01:53:08 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int subarraysDivByK1(vector<int>& A, int K) {
    int res = 0;
    int size = A.size();
    for (int i = 0; i < size; ++i)
    {
        int sum = 0;
        for (int j = i; j < size; ++j)
        {
            sum += A[j];
            if (sum % K == 0)
                res++;
        }
    }
    return res;
}
int subarraysDivByK2(vector<int>& A, int K) {
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    for (int& a : A)
    {
        sum += a;
        int m = (sum % K + K) % K;
        ++map[m];
    }
    int result = 0;
    for (auto &x : map)
    {
        int c = x.second;
        result += c * (c - 1) / 2;
    }
    return result;
}
int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> map;
    map[0] = 1;
    int res = 0;
    int sum = 0;
    for (int &elem : A)
    {
        sum += elem;
        int m = (sum % K + K) % K;
        res += map[m];
        map[m]++;    
    }
    return res;
}
