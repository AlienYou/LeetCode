/*************************************************************************
	> File Name: LeetCode_836.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Mar 2020 08:23:08 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec2[2] <= rec1[0] || rec2[3] <= rec1[1]);
}
