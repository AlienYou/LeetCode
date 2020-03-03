/*************************************************************************
	> File Name: LeetCode_933.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Mar 2020 07:24:59 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {
    
    }
    
    int ping(int t) {
        record.push_back(t);
        t = t - 3000;
        int count = 0;
        if (t <= 0)
            count = record.size();
        else
        {
            int start = 0;
            int end = record.size() - 1;
            while (start <= end)
            {
                int mid = (start + end) >> 1;
                if (t > record[mid])
                    start = mid + 1;
                else if (t < record[mid])
                    end = mid - 1;
                else 
                {
                    start = mid;
                    break;
                }                    
            }
            count = record.size() - start;
        }
        return count;
    }
private:
    vector<int> record;
};
