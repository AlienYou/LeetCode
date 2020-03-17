/*************************************************************************
	> File Name: LeetCode_1160.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Mar 2020 08:04:06 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    int result = 0;
    int charMap[26] = {0};
    for (int i = 0; i < chars.size(); ++i)
        charMap[chars[i] - 'a']++;
    for (int i = 0; i < words.size(); ++i)
    {
        bool isFormed = true;
        int curCount[26] = {0};
        copy(charMap, charMap + 26, curCount);
        for (int j = 0; j < words[i].length(); ++j)
        {
            curCount[words[i][j] - 'a']--;
            if (curCount[words[i][j] - 'a'] < 0)
            {
                isFormed = false;
                break;
            }
        }
        if (isFormed)
            result += words[i].length();
    }
    return result;
}
