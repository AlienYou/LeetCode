/*************************************************************************
	> File Name: LeetCode_146_2.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Mar 2020 05:06:45 AM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
public:
    using lIt = list<pair<int,int>>::iterator;
    using unmIt = unordered_map<int, lIt>::iterator;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        unmIt it = cacheMap.find(key);
        if (it == cacheMap.end())
            return -1;
        auto p = *cacheMap[key];
        cache.push_front(p);
        cache.erase(cacheMap[key]);
        cacheMap[key] = cache.begin();
        return p.second;
    }

    void put(int key, int value) {
        unmIt it = cacheMap.find(key);
        auto p = make_pair(key, value);
        if (it != cacheMap.end())
        {
            cache.push_front(p);
            cache.erase(cacheMap[key]);
            cacheMap[key] = cache.begin();
        }
        else
        {
            if (cache.size() >= size)
            {
                auto last = cache.back();
                cache.pop_back();
                cacheMap.erase(last.first);
            }
            cache.push_front(p);
            cacheMap.insert(make_pair(key, cache.begin()));
        }
    }
private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, lIt> cacheMap;
};
