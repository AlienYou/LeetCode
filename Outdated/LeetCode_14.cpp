/*************************************************************************
	> File Name: LeetCode_14.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Mar 2020 07:14:47 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result;
    if (strs.size() == 0)
        return result;
    int minLength = 0xFFFFFFF;
    for (int i = 0; i < strs.size(); ++i)
        if (minLength > strs[i].length())
            minLength = strs[i].length();
    for (int i = 0; i < minLength; ++i)
    {
        int j = 1;
        bool prefix = true;
        for (; j < strs.size(); ++j)
        {
            if (strs[j][i] != strs[j - 1][i])
                return result;
        }
            result += strs[j - 1][i];
    }
    return result;
}

class Solution {
public:
    struct Trie
    {
        int size;
        Trie* word[26];
        bool isEnd = false;
        Trie()
        {
            size = 0;
            for (int i = 0; i < 26; ++i)
                word[i] = nullptr;
        }
        ~Trie()
        {
            for (int i = 0; i < 26; ++i)
                if (word[i] != nullptr)
                    word[i]->~Trie();
            delete this;
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0)
            return ans;
        Trie* root = new Trie();
        int size = strs.size();
        for (int i = 0; i < size; ++i)
        {
            Trie* p = root;
            if (strs[i].length() == 0)
                return ans;
            for (int j = 0; j < strs[i].length(); ++j)
            {
                if (p->word[strs[i][j] - 'a'] == nullptr)
                {
                    p->size++;
                    p->word[strs[i][j] - 'a'] = new Trie();
                }
                p = p->word[strs[i][j] - 'a'];
            }
            p->isEnd = true;
        }
        Trie* p = root;
        while (p->size == 1 && p->isEnd == false)
        {
            int i = 0;
            for (; i < 26; ++i)
            {
                if (p->word[i] != nullptr)
                {
                    char temp = i + 'a';
                    ans += temp;
                    break;
                }
            }
            p = p->word[i];
        }
        return ans;
    }
};
