/*************************************************************************
	> File Name: LeetCode_355.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Apr 2020 09:11:49 AM PDT
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;
class Twitter {
public:
    struct TwMsg
    {
        int tweetID;
        int T;
        TwMsg(int twId, int t) : tweetID(twId), T(t) {}
    };
    typedef unordered_map<int, list<TwMsg>>::iterator mIt;
    typedef unordered_map<int, unordered_set<int>>::iterator msIt;
    enum{TweetNums = 10};
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        TwMsg twmsg = TwMsg(tweetId, time++);
        userTweetMes[userId].emplace_front(twmsg);
    }
    class CmpTwMsg
    {
    public:
        bool operator()(const TwMsg& node1, const TwMsg& node2)
        {
            return node1.T > node2.T;
        }
    };
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        mIt it = userTweetMes.find(userId);
        if (it == userTweetMes.end())
            return vector<int>();
        priority_queue<TwMsg, vector<TwMsg>, CmpTwMsg> tweetHeap;
        vector<int> result;
        list<TwMsg>::iterator lit = it->second.begin();
        for (int i = 0; i < TweetNums; ++i)
        {
            if (lit == it->second.end())
                break;
            tweetHeap.push(*lit);
            ++lit;
        }
        unordered_set<int>::iterator sit = userFollowMap[userId].begin();
        for (; sit != userFollowMap[userId].end(); ++sit)
        {
            lit = userTweetMes[*sit].begin();
            for (; lit != userTweetMes[*sit].end(); ++lit)
            {
                if (tweetHeap.size() < 10)
                {
                    tweetHeap.push(*lit);
                    continue;
                }    
                if (tweetHeap.top().T < lit->T)
                {
                    tweetHeap.pop();
                    tweetHeap.push(*lit);
                }
                else
                    break;
            }
        }
        while (!tweetHeap.empty())
        {
            result.push_back(tweetHeap.top().tweetID);
            tweetHeap.pop();
        }

        int begin = 0, end = result.size() - 1;
        while (begin < end)
        {
            swap(result[begin++], result[end--]);
        }

        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        userFollowMap[followerId].insert(followeeId);
        mIt mit = userTweetMes.find(followerId);
        if (mit == userTweetMes.end())
            userTweetMes[followerId] = list<TwMsg>();
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        msIt mit = userFollowMap.find(followerId);
        if (mit == userFollowMap.end())
            return;
        unordered_set<int>::iterator sit = userFollowMap[followerId].find(followeeId);
        if (sit == userFollowMap[followerId].end())
            return;
        userFollowMap[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> userFollowMap;
    unordered_map<int, list<TwMsg>> userTweetMes;
    int time;
};
