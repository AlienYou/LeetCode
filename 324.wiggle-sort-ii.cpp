/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (30.49%)
 * Likes:    1322
 * Dislikes: 647
 * Total Accepted:    96.2K
 * Total Submissions: 312.9K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an integer array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * You may assume the input array always has a valid answer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,1,1,6,4]
 * Output: [1,6,1,5,1,4]
 * Explanation: [1,4,1,5,1,6] is also accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,2,2,3,1]
 * Output: [2,3,1,3,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5000
 * It is guaranteed that there will be an answer for the given input nums.
 * 
 * 
 * 
 * Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// @lc code=start
struct TrieNode {
    vector<TrieNode*> next;
    string word;
    TrieNode() : next(26, nullptr) { }
};
class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords1(vector<vector<char>>& board, vector<string>& words) {
        int wordLength = words.size();
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for (int l = 0; l < wordLength; ++l) {
            bool find = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == words[l][0] && DFS(board, i, j, m, n, 0, words[l])) {
                        res.push_back(words[l]);
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }
        }
        return res;
    }
    
    bool DFS(vector<vector<char>>& board, int r, int c, int rows, int cols, int ind, string& word) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[ind])
            return false;
        if (ind == word.length() - 1)
            return true;
        bool isExist = false;
        char orig = board[r][c];
        board[r][c] = '*';
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            isExist = isExist || DFS(board, nr, nc, rows, cols, ind + 1, word);
        }
        board[r][c] = orig;
        return isExist;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        TrieNode* node = root;
        for (int i = 0; i < words.size(); ++i) 
            buildTrieTree(words[i]);
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                DFS_Trie(board, i, j, m, n, res, node);
            }
        }
        return res;
    }
    void DFS_Trie(vector<vector<char>>& board, int r, int c, int rows, int cols, vector<string>& res, TrieNode* node) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '*' || node->next[board[r][c] - 'a'] == nullptr)
            return;
        char orig = board[r][c];
        board[r][c] = '*';
        if (node->next[orig - 'a']->word.size() > 0) {
            res.push_back(node->next[orig - 'a']->word);
            node->next[orig - 'a']->word.clear();
        }
        node = node->next[orig - 'a'];
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            DFS_Trie(board, nr, nc, rows, cols, res, node);
        }
        board[r][c] = orig;
    }
private:
    TrieNode* root;
    
    void buildTrieTree(const string& s) {
        TrieNode* node = root;
        
        for (int i = 0; i < s.length(); ++i) {
            int cur = s[i] - 'a';
            if (node->next[cur] == nullptr) {
                node->next[cur] = new TrieNode();
            }
            node = node->next[cur];
        }
        node->word = s;
    }
};

// @lc code=end

