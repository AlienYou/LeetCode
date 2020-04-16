/*************************************************************************
	> File Name: LeetCode_56.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Apr 2020 12:53:37 AM PDT
 ************************************************************************/

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)
        return intervals;
    sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    });
    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); ++i)
    {
        int j;
        vector<int> mergeVec;
        int right = intervals[i][1];
        for (j = i + 1; j < intervals.size(); ++j)
        {
            if (right < intervals[j][0])
                break;
            right = max(right, intervals[j][1]);
        }
        mergeVec.push_back(intervals[i][0]);
        mergeVec.push_back(right);
        result.emplace_back(mergeVec);
        if (j - 1 > i)
            i = j - 1;
    }
    return result;
}

vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)
        return intervals;
    sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    });
    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); ++i)
    {
        int left = intervals[i][0], right = intervals[i][1];
        if (!result.size() || result.back()[1] < left)
        {
            result.push_back({left, right});
        }
        else
        {
            result.back()[1] = max(result.back()[1], right);
        }
    }
    return result;
}

