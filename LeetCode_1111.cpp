/*************************************************************************
	> File Name: LeetCode_1111.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Mar 2020 10:41:26 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    vector<int> result(seq.length());
    int index = 0;
    for (char& c : seq)
    {
        result[index++] = c == '(' ? index & 1 : (index + 1) & 1;
    }
    return result;
}
