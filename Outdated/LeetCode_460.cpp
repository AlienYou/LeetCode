/*************************************************************************
	> File Name: LeetCode_460.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Apr 2020 11:15:01 PM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

struct Node
{
    int key;
    int value;
    int freq;
    Node(int k, int v, int f = 1) : key(k), value(v), freq(f) {}
};

class LFUCache {
public:
    typedef int Freq;
    typedef int Key;
    typedef unordered_map<Key, list<Node>::iterator>::iterator kmIte;
    typedef unordered_map<Freq, list<Node>>::iterator flIte; 
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (capacity == 0)
            return -1;
        kmIte kIt = keyMap.find(key);
        if (kIt == keyMap.end())
            return -1;
        auto listIt = kIt->second;
        int val = listIt->value;
        Freq lastFreq = listIt->freq;
        listIt->freq += 1;
        flIte lIt = freqMap.find(listIt->freq);
        freqMap[listIt->freq].splice(freqMap[listIt->freq].begin(), freqMap[lastFreq], listIt);
        if (freqMap[lastFreq].size() == 0)
        {    
            freqMap.erase(lastFreq);
            if (minUsed == lastFreq)
                minUsed = listIt->freq;
        }
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        kmIte kmIt = keyMap.find(key);
        if (kmIt != keyMap.end())
        {
            auto listIt = kmIt->second;
            listIt->value = value;
            int lastFreq = listIt->freq;
            listIt->freq += 1;
            freqMap[listIt->freq].splice(freqMap[listIt->freq].begin(), freqMap[lastFreq], listIt);
            if (freqMap[lastFreq].size() == 0)
            {    
                freqMap.erase(lastFreq);
                if (minUsed == lastFreq)
                    minUsed = listIt->freq;
            }
        }
        else
        {
            if (keyMap.size() >= capacity)
            {
                int key = freqMap[minUsed].back().key;
                list<Node>::iterator lIt = keyMap[key]; 
                keyMap.erase(key);
                freqMap[minUsed].erase(lIt);
            }
            Node newNode = {key, value};
            freqMap[newNode.freq].push_front(newNode);
            keyMap[key] = freqMap[newNode.freq].begin();
            minUsed = 1;
        }
    }
private:
    int capacity;
    unordered_map<Key, list<Node>::iterator> keyMap;
    unordered_map<Freq, list<Node>> freqMap;
    int minUsed;
};

int main()
{
    LFUCache cache(2);
    cache.put(1, 1);//1,1,1
    cache.put(2, 2);//2,1,2
    cout << cache.get(1) << endl;//1,2,1
    cache.put(3, 3);//3,1,3
    cout << cache.get(2) << endl;//2,2,2
    cout << cache.get(3) << endl;//3,2,3
    cache.put(4, 4);
    cout << cache.get(1) << endl;
}
