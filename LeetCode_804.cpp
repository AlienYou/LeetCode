/*************************************************************************
	> File Name: LeetCode_804.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Feb 2020 08:08:49 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

#define MORSENUM 26

const string MorseMap[MORSENUM] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int UniqueMorseRepresentations(vector<string>& words)
{
    vector<string> morseTrans;
    morseTrans.resize(words.size());
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j < words[i].length(); ++j)
        {
            morseTrans[i].append(MorseMap[words[i][j] - 'a']);
        }
    }
    int count = 0;
    sort(morseTrans.begin(), morseTrans.end());
    string temp = morseTrans[0];
    for (int i = 1; i < morseTrans.size(); ++i)
    {
        if (temp != morseTrans[i])
        {
            ++count;
            temp = morseTrans[i];
        }
    }
    return count + 1;
}

int UniqueMorseRepresentations_2(vector<string>& words)
{
    set<string> stringMap;
    for (int i = 0; i < words.size(); ++i)
    {
        string str;
        for (int j = 0; j < words[i].length(); ++j)
            str.append(MorseMap[words[i][j] - 'a']);
        stringMap.insert(str); 
    }
    return stringMap.size();
}

void test(const char* testName, vector<string>& words)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    printf("1:%d\n",UniqueMorseRepresentations(words));
    printf("2:%d\n", UniqueMorseRepresentations_2(words));
}

void test1()
{
    string morse[4] = { "gin", "zen", "gig", "msg" };
    vector<string> words;
    for (int i = 0; i < 4; ++i)
        words.push_back(morse[i]);
    test("Test1", words);
}

int main()
{
    test1();
}
