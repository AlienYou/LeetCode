/*************************************************************************
	> File Name: LeetCode_821.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Mar 2020 10:35:21 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> shortestToChar(string S, char C) {
    vector<int> cIndex;
    vector<int> result(S.length(), 0);
    for (int i = 0; i < S.length(); ++i)
        if (S[i] == C) cIndex.push_back(i);
    for (int i = 0; i < S.length(); ++i)
    {
        if (S[i] != C)
        {
            int smallest = 10000;
            for (int j = 0; j < cIndex.size(); ++j)
                smallest = min(smallest, abs(cIndex[j] - i));
            result[i] = smallest;
        }
    }
    return result;
}
