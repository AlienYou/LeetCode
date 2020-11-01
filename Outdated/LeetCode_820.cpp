/*************************************************************************
	> File Name: LeetCode_820.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Mar 2020 08:40:50 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<forward_list>
using namespace std;

//超时。。。。。。。
int isSubstring(string s1, string s2)
{
    int value = 1;
    if (s1.length() < s2.length())
    {    
        swap(s1, s2);
        value = -1;
    }
    int maxL = s1.length() - 1;
    int minL = s2.length() - 1;
    while (minL >= 0)
    {
        if (s1[maxL--] != s2[minL--])
            return 0;
    }
    return value;
}

int MinimumLengthEncoding(vector<string>& words)
{
    using flIte = forward_list<string>::iterator;
    if (words.size() == 0)
        return 0;
    forward_list<string> result; 
    result.push_front(words[0]);
    for (int i = 1; i < words.size(); ++i)
    {
        flIte it;
        for (it = result.begin(); it != result.end();)
        {
            int value = isSubstring(*it, words[i]);
            if (value == 0)
                ++it;
            else if (value == 1)
                break;
            else if (value == -1)
            {
                flIte dele = it;
                ++it;
                result.remove(*dele);
            }
        }
        if (it == result.end())
            result.push_front(words[i]);
    }
    int ans = 0;
    for (auto& x : result)
         ans += x.length() + 1;
    return ans;
}

//超时。。。。

 int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> stringSet(words.begin(), words.end());
    for (auto& s : words)
    {
        for (int i = 1; i < s.length(); ++i)
        {
            stringSet.erase(s.substr(i));
        }
    }
    int ans = 0;
    for (auto& s : stringSet)
    {
        ans += s.length() + 1;
    }
    return ans;
}

