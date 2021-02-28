/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (31.03%)
 * Likes:    4617
 * Dislikes: 1391
 * Total Accepted:    540.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words such that:
 * 
 * 
 * The first word in the sequence is beginWord.
 * The last word in the sequence is endWord.
 * Only one letter is different between each adjacent pair of words in the
 * sequence.
 * Every word in the sequence is in wordList.
 * 
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog"
 * -> "cog" with 5 words.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * possible transformation.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the strings in wordList are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int L = 0;
    unordered_map<string, vector<string>> allComboDict;
    
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        this->L = beginWord.length();
        
        for (auto w : wordList) {
            for (int i = 0; i < this->L; ++i) {
                string newWord = w.substr(0, i) + '*' + w.substr(i + 1, this->L);
                this->allComboDict[newWord].push_back(w);
            }
        }
        queue<pair<string, int>> que;
        que.push(make_pair(beginWord, 1));
        
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            string word = p.first;
            int level = p.second;
            for (int i = 0; i < this->L; ++i) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);
                for (auto w : this->allComboDict[newWord]) {
                    if (w == endWord) {
                        return level + 1;
                    }
                    if (!visited.count(w)) {
                        visited[w] = true;
                        que.push(make_pair(w, level + 1));
                    }
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        this->L = beginWord.length();
        bool canTransform = false;
        for (auto w : wordList) {
            for (int i = 0; i < this->L; ++i) {
                string newWord = w.substr(0, i) + '*' + w.substr(i + 1, this->L);
                this->allComboDict[newWord].push_back(w);
            }
            if (w == endWord)
                canTransform = true;
        }
        if (!canTransform)
            return 0;
        queue<pair<string, int>> q_begin;
        queue<pair<string, int>> q_end;
        
        unordered_map<string, int> visitedBegin;
        unordered_map<string, int> visitedEnd;
        
        q_begin.push(make_pair(beginWord, 1));
        q_end.push(make_pair(endWord, 1));
        visitedBegin[beginWord] = 1;
        visitedEnd[endWord] = 1;
        
        while (!q_begin.empty() && !q_end.empty()) {
            int ans = visitWordNode(q_begin, visitedBegin, visitedEnd);
            if (ans > -1) {
                return ans;
            }
            ans = visitWordNode(q_end, visitedEnd, visitedBegin);
            if (ans > -1){
                return ans;
            }
        }
        return 0;
    }
    
    int visitWordNode(queue<pair<string, int>>& que, unordered_map<string, int>& visited, unordered_map<string, int>& otherVisited) {
        auto node = que.front();
        que.pop();
        string word = node.first;
        int level = node.second;
        
        for (int i = 0; i < this->L; ++i) {
            string newWord = word.substr(0, i) + '*' + word.substr(i + 1, this->L);
            for (auto w : this->allComboDict[newWord]) {
                if (otherVisited.count(w)) {
                    return level + otherVisited[w];
                }
                if (!visited.count(w)) {
                    visited[w] = level + 1;
                    que.push(make_pair(w, level + 1));
                }
            }
            
        }
        return -1;
    }
};
// @lc code=end

