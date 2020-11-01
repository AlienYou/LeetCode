/*************************************************************************
	> File Name: LeetCode_914.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Mar 2020 07:13:29 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool hasGroupsSizeX(vector<int>& deck) {
    if (deck.size() == 1)
        return false;
    int maxL = 0;
    int map[10001] = {0};
    for (int i = 0; i < deck.size(); ++i)
    {
        map[deck[i]]++;
        maxL = max(maxL, map[deck[i]]);
    }
    int minNum = 0;
    for (int i = 0; i <= maxL; ++i)
    {    
        if (map[i] > 0) 
        {
            minNum = gcd(minNum, map[i]);
            if (minNum == 1)
                return false;
        }
    }           
    return true;
}
