/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 *
 * https://leetcode.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    1980
 * Dislikes: 71
 * Total Accepted:    117.2K
 * Total Submissions: 214.2K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can
 * rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
 * to be '9'. Each move consists of turning one wheel one slot.
 * 
 * The lock initially starts at '0000', a string representing the state of the
 * 4 wheels.
 * 
 * You are given a list of deadends dead ends, meaning if the lock displays any
 * of these codes, the wheels of the lock will stop turning and you will be
 * unable to open it.
 * 
 * Given a target representing the value of the wheels that will unlock the
 * lock, return the minimum total number of turns required to open the lock, or
 * -1 if it is impossible.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
 * "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * would be invalid,
 * because the wheels of the lock become stuck after the display becomes the
 * dead end "0102".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * Output: -1
 * Explanation:
 * We can't reach the target without getting stuck.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= deadends.length <= 500
 * deadends[i].length == 4
 * target.length == 4
 * target will not be in the list deadends.
 * target and deadends[i] consist of digits only.
 * 
 * 
 */

//难想到，这道题需要把它抽象成图
//图中每个节点都是一个解，找到匹配题目中要求的解所需要的最短路径
//那么可以考虑使用BFS去做
//需要注意每一步都可以旋转Lock任意一个wheel，所有有getAllNextCode函数


// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        string begin = "0000"; 
        if (dds.find(begin) != dds.end()) return -1;
        visited.insert(begin);
        queue<string> bfs;
        bfs.push(begin);
        int res = 0;
        
        while (!bfs.empty()) {
            int sz = bfs.size();
            for (int i = 0; i < sz; ++i) {
                string cur = bfs.front();
                bfs.pop();
                if (cur == target)
                    return res;
                vector<string> codes = getAllNextCode(cur);
                for (int j = 0; j < codes.size(); ++j) {
                    if (visited.count(codes[j]))
                        continue;
                    if (!dds.count(codes[j])) {
                        visited.insert(codes[j]);
                        bfs.push(codes[j]);
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
    vector<string> getAllNextCode(string& s) {
        vector<string> codes;
        for(int i = 0; i < 4; ++i) 
        {
            string temp = s;
            temp[i] = (s[i] - '0' + 1) % 10 + '0';
            codes.push_back(temp);
            temp[i] = (s[i] - '0' + 9) % 10 + '0';
            codes.push_back(temp);
        }
        return codes;
    }
};
// @lc code=end

